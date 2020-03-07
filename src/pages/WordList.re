open Utils;

[@react.component]
let make = () => {
  let (state, _send) = Hooks.useApi();

  let search =
    <Search modifyContainerCss={Some("mb-6")} modifySearchCss={Some("")} />;

  <section className="hero is-large pb-16">
    <div className="p-6">
      search
      {switch (state.result) {
       | Pending => <div> "Loading..."->React.string </div>
       | Loading => <div> "Loading..."->React.string </div>
       | Complete(result) =>
         switch (result) {
         | Ok(result) =>
           Belt.Array.length(result.data) < 1
             ? <div className="text-xl  mb-4">
                 "Sorry, no matches found."->React.string
               </div>
             : <div>
                 <div className="text-xl mb-4">
                   "We were able to find "->text
                   {Belt.Array.length(result.data)->Js.Int.toString->text}
                   " match"->text
                   {Belt.Array.length(result.data) === 1 ? "" : "es"}->text
                 </div>
                 <div className="flex flex-wrap">
                   {result.data
                    ->Belt.Array.map(entry =>
                        <Match key={entry.creek} entry />
                      )
                    ->React.array}
                 </div>
               </div>
         | Error(_err) => <div> "There was an error :("->React.string </div>
         }
       }}
    </div>
  </section>;
};

let default = make;
