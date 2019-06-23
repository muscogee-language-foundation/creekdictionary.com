[%raw "require(\"../../../src/global.css\")"];

let make = () => {
  let url = ReasonReact.Router.useUrl();
  <Frame>
    {switch (url.path) {
     | [] => <Home />
     | ["about"] => <About />
     | ["resources"] => <Resources />
     | ["history"] => <History />
     | ["search"] => <WordList />
     | [id] => <Word id />
     | _ => <NotFound />
     }}
  </Frame>;
};
