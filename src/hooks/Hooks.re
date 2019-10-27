type state = {
  result: Relude.AsyncResult.t(Utils.entries, ReludeFetch.Error.t(string)),
};
type action =
  | FetchWords
  | FetchWordsSuccess(Utils.entries)
  | FetchWordsError(ReludeFetch.Error.t(string));

let initialState = {result: Relude.AsyncResult.init};

let reducer = (state, action) => {
  switch (action) {
  | FetchWords =>
    let location = ReasonReact.Router.dangerouslyGetInitialUrl();
    let query = location.search;
    let url = Utils.apiUrl ++ Utils.decodeURIComponent(query);

    ReludeReact.Reducer.UpdateWithIO(
      {result: state.result |> Relude.AsyncResult.toBusy},
      ReludeFetch.get(url)
      |> Relude.IO.flatMap(a =>
           ReludeFetch.Response.json(a)
           |> Relude.IO.map(Utils.Decode.decodeEntries)
         )
      |> Relude.IO.bimap(a => FetchWordsSuccess(a), e => FetchWordsError(e)),
    );
  | FetchWordsSuccess(data) =>
    ReludeReact.Reducer.Update({result: Relude.AsyncResult.completeOk(data)})
  | FetchWordsError(error) =>
    ReludeReact.Reducer.Update({
      result: Relude.AsyncResult.completeError(error),
    })
  };
};

let useApi = () => {
  let url = ReasonReact.Router.useUrl();

  let (state, send) = ReludeReact.Reducer.useReducer(reducer, initialState);

  ReludeReact.Effect.useOnMount(() => send(FetchWords));

  React.useEffect1(() => Some(() => send(FetchWords)), [|url.search|]);

  (state, send);
};
