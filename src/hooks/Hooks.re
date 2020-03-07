[@bs.module] external words: Js.Json.t = "../../../../src/words.json";

let wordsData = Js.Dict.fromList([("data", words)]) |> Js.Json.object_;

let decodedWordsData = Utils.Decode.decodeEntries(wordsData);

type remoteData('a, 'b) =
  | Pending
  | Loading
  | Complete(Belt.Result.t('a, 'b));

type data = remoteData(Utils.entries, string);

type action =
  | FetchWords
  | FetchWordsSuccess(Utils.entries)
  | FetchWordsError(string);

type state = {result: remoteData(Utils.entries, string)};

let initialState = {result: Pending};

let useApi = () => {
  let url = ReasonReact.Router.useUrl();

  let (state, send) =
    ReactUpdate.useReducer(initialState, (action, _state) =>
      switch (action) {
      | FetchWords =>
        UpdateWithSideEffects(
          {result: Loading},
          ({send}) => {
            let location = ReasonReact.Router.dangerouslyGetInitialUrl();
            let query = location.search;
            let foundWords =
              query
              ->Utils.extractQuery
              ->Utils.decodeURIComponent
              ->Utils.find(decodedWordsData.data);
            let result: Utils.entries = {data: foundWords};

            send(FetchWordsSuccess(result));

            None;
          },
        )
      | FetchWordsSuccess(data) => Update({result: Complete(Ok(data))})
      | FetchWordsError(err) => Update({result: Complete(Error(err))})
      }
    );

  React.useEffect0(() => {
    send(FetchWords);
    None;
  });

  React.useEffect1(() => Some(() => send(FetchWords)), [|url.search|]);

  (state, send);
};
