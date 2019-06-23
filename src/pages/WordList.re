open Utils;

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();
  let query = decodeURIComponent(url.search);

  let matches =
    Belt.Option.(
      Js.String.split("=", query)
      ->Belt.Array.get(1)
      ->map(words => {
          Js.log(words);
          Belt.Array.keep(Utils.data, entry =>
            Js.String.includes(entry.creek, words)
            || Js.String.includes(entry.english, words)
          );
        })
      ->map(matches =>
          Belt.Array.map(matches, ({creek}) =>
            <div
              key=creek
              style={ReactDOMRe.Style.make(~width="100%", ())}
              className="box">
              {j|$creek|j}->text
            </div>
          )
        )
      ->getWithDefault([||])
    )
    ->React.array;

  <section className="hero is-large">
    <div
      style={ReactDOMRe.Style.make(~paddingTop="24px", ())}
      className="container is-fluid">
      matches
    </div>
  </section>;
};
