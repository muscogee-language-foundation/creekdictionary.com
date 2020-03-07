open Utils;

type action =
  | Input(string);

type state = {
  words: string,
  encodedWords: string,
};

[@react.component]
let make =
    (~modifyButtonCss=None, ~modifySearchCss=None, ~modifyContainerCss=None) => {
  let location = ReasonReact.Router.dangerouslyGetInitialUrl();
  let query = location.search;
  let words = query->extractQuery->decodeURIComponent;
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Input(words) => {words, encodedWords: words->encodeURIComponent}
        },
      {words, encodedWords: words->encodeURIComponent},
    );

  /**
   * Multiple words are not encoded when pushed to the url for some reason
   * Need to invetigage this further
   * AR - 2020/03/07
   */
  let {words, encodedWords} = state;

  <div className={Belt.Option.getWithDefault(modifyContainerCss, "")}>
    <form
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        push({j|/search?q=$encodedWords|j});
      }}>
      <input
        autoFocus=true
        value=words
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          dispatch(Input(value));
        }}
        className={
          "min-w-full sm:min-w-0 border-t-2 border-b-2 border-l-2 border-r-2 rounded sm:rounded-r-none py-2 px-4 border-gray-200 md:text-2xl text-gray-900 sm:text-xl sm:border-r-0 mb-2"
          ++ Belt.Option.getWithDefault(modifySearchCss, "")
        }
        placeholder="Search by Creek or English"
        type_="text"
      />
      <button
        className={
          "min-w-full sm:min-w-0 sm:rounded-l-none  bg-blue-500 py-2 px-4 border-2 border-blue-500 rounded text-white md:text-2xl sm:text-xl "
          ++ Belt.Option.getWithDefault(modifyButtonCss, "")
        }
        type_="submit">
        "Search"->text
      </button>
    </form>
  </div>;
};
