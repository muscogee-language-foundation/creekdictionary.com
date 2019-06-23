open Utils;

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();
  let query = decodeURIComponent(url.search);

  let matches =
    Belt.Option.(
      Js.String.split("=", query)
      ->Belt.Array.get(1)
      ->flatMap(words => {
          let matches =
            Belt.Array.keep(Utils.data, entry =>
              Js.String.includes(entry.creek, words)
              || Js.String.includes(entry.english, words)
              || Belt.Array.some(Js.String.split(",", entry.tags), tag =>
                   Js.String.includes(tag, words)
                 )
            );

          Belt.Array.length(matches) > 0 ? Some(matches) : None;
        })
      ->map(matches =>
          <div>
            {Belt.Array.map(matches, entry => <Match entry />)->React.array}
          </div>
        )
      ->getWithDefault(
          <div className="">
            <div className="text-xl text-center">
              {j|Sorry but I could not find any matches 😞|j}->text
            </div>
            <div className="text-xl mb-4 text-center">
              {j|Here are some other words instead 👇|j}->text
            </div>
            <div>
              {Belt.Array.map(Utils.data, entry => <Match entry />)
               ->React.array}
            </div>
          </div>,
        )
    );

  <section className="hero is-large">
    <div className="p-6"> matches </div>
  </section>;
};

let default = make;
