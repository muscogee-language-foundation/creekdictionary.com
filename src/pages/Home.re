open Utils;

type action =
  | Input(string);

type state = {
  words: string,
  encodedWords: string,
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Input(words) => {words, encodedWords: encodeURIComponent(words)}
        },
      {words: "", encodedWords: ""},
    );

  let {words, encodedWords} = state;
  <section className="pb-16 pt-64 px-6 flex justify-center">
    <form
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        push({j|/search?query=$encodedWords|j});
      }}>
      <input
        value=words
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          dispatch(Input(value));
        }}
        className="border-t-2 border-b-2 border-l-2 rounded-l py-2 px-4 border-gray-200 text-2xl text-gray-900"
        placeholder="Search by Creek or English"
        type_="text"
      />
      <button
        className="bg-blue-500 py-2 px-4 border-2 border-blue-500 rounded-r text-white text-2xl"
        type_="submit">
        "Search"->text
      </button>
    </form>
  </section>;
};
