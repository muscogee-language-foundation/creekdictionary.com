open Utils;

[@react.component]
let make = () => {
  let (state, _send) = Hooks.useApi();

  let search =
    <Search modifyContainerCss={Some("mb-6")} modifySearchCss={Some("")} />;

  <section className="hero is-large pb-16">
    <div className="p-6">
      search
      {state.result
       |> ReludeReact.Render.asyncResultByValueLazy(
            _ => <div> "Loading..."->React.string </div>,
            result =>
              Relude.Array.length(result.data) < 1
                ? <div className="text-xl  mb-4">
                    "Sorry, no matches found."->React.string
                  </div>
                : <div>
                    <div className="text-xl mb-4">
                      "We were able to find "->text
                      {string_of_int(Relude.Array.length(result.data))->text}
                      " match"->text
                      {Relude.Array.length(result.data) === 1 ? "" : "es"}
                      ->text
                    </div>
                    <div className="flex flex-wrap">
                      {result.data
                       |> Relude.Array.map(entry => <Match entry />)
                       |> React.array}
                    </div>
                  </div>,
            _error => <div> "There was an error :("->React.string </div>,
          )}
    </div>
  </section>;
};

let default = make;
