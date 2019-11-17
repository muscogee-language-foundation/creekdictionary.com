[@bs.module] external words: Js.Json.t = "../../../../src/words.json";

let wordsData = Js.Dict.fromList([("data", words)]) |> Js.Json.object_;

let decodedWordsData = Utils.Decode.decodeEntries(wordsData);

let find = search =>
  Relude.Array.filter((entry: Utils.entry) =>
    Utils.includesCaseInsensitive(~target=entry.creek, ~search)
    || Utils.includesCaseInsensitive(~target=entry.english, ~search)
  );

type state = {
  result: Relude.AsyncResult.t(Utils.entries, ReludeFetch.Error.t(string)),
};
type action =
  | FetchWords
  | FetchWordsSuccess(Utils.entries)
  | FetchWordsError(ReludeFetch.Error.t(string));

let initialState = {result: Relude.AsyncResult.init};

let reducer = (useLocalData, state, action) => {
  switch (action) {
  | FetchWords =>
    let location = ReasonReact.Router.dangerouslyGetInitialUrl();
    let query = location.search;
    let url = Utils.apiUrl ++ Utils.decodeURIComponent(query);
    let term =
      Js.String.split("=", query)
      ->Belt.Array.get(1)
      ->Belt.Option.getWithDefault("");
    let foundTerms = find(term, decodedWordsData.data);
    let result: Utils.entries = {data: foundTerms};

    useLocalData
      ? ReludeReact.Reducer.Update({
          result: Relude.AsyncResult.completeOk(result),
        })
      : ReludeReact.Reducer.UpdateWithIO(
          {result: state.result |> Relude.AsyncResult.toBusy},
          ReludeFetch.get(url)
          |> Relude.IO.flatMap(a =>
               ReludeFetch.Response.json(a)
               |> Relude.IO.map(Utils.Decode.decodeEntries)
             )
          |> Relude.IO.bimap(
               a => FetchWordsSuccess(a),
               e => FetchWordsError(e),
             ),
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

  let (state, send) =
    ReludeReact.Reducer.useReducer(reducer(true), initialState);

  ReludeReact.Effect.useOnMount(() => send(FetchWords));

  React.useEffect1(() => Some(() => send(FetchWords)), [|url.search|]);

  (state, send);
};
