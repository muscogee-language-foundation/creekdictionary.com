let make = () => {
  let url = ReasonReact.Router.useUrl();
  <Frame>
    {switch (url.path) {
     | [] => <Home />
     | ["about"] => <LazyAbout />
     //  | ["resources"] => <Resources />
     //  | ["history"] => <History />
     | ["search"] => <LazyWordList />
     //  | [id] => <Word id />
     | _ => <LazyNotFound />
     }}
  </Frame>;
};

let default = make;
