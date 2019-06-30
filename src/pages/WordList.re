open Utils;

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();

  let search =
    <Search modifyContainerCss={Some("mb-6")} modifySearchCss={Some("")} />;

  let query =
    Js.String.split("=", decodeURIComponent(url.search))->Belt.Array.get(1);

  let matches =
    Belt.Option.(
      query
      ->flatMap(words => {
          let matches =
            Belt.Array.keep(Utils.data, entry =>
              Js.String.includes(
                Js.String.toLocaleLowerCase(words),
                Js.String.toLocaleLowerCase(entry.creek),
              )
              || Js.String.includes(
                   Js.String.toLocaleLowerCase(words),
                   Js.String.toLocaleLowerCase(entry.english),
                 )
              || Belt.Array.some(Js.String.split(",", entry.tags), tag =>
                   Js.String.includes(
                     Js.String.toLocaleLowerCase(tag),
                     Js.String.toLocaleLowerCase(words),
                   )
                 )
            );

          Belt.Array.length(matches) > 0 ? Some(matches) : None;
        })
      ->map(matches =>
          <div>
            search
            <div className="text-xl mb-4">
              "We were able to find "->text
              {string_of_int(Belt.Array.length(matches))->text}
              " match"->text
              {Belt.Array.length(matches) === 1 ? "" : "es"}->text
            </div>
            <div className="flex flex-wrap">
              {Belt.Array.map(matches, entry => <Match entry />)->React.array}
            </div>
          </div>
        )
      ->getWithDefault(
          <div>
            search
            <div className="text-xl  mb-4">
              {map(query, q =>
                 <span>
                   "Sorry, we could not find any matches for "->text
                   <span className="italic"> q->text </span>
                   "."->text
                 </span>
               )
               ->getWithDefault(
                   <span>
                     {j|Sorry, we could not find any matches.|j}->text
                   </span>,
                 )}
            </div>
            <div className="flex flex-wrap ">
              {Belt.Array.map(Utils.data, entry => <Match entry />)
               ->React.array}
            </div>
          </div>,
        )
    );

  <section className="hero is-large pb-16">
    <div className="p-6 "> matches </div>
  </section>;
};

let default = make;
