module type T = (module type of NotFound);

[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  let make =
    ReLoadable.lazy_(() =>
      DynamicImport.import("../../../../lib/js/src/pages/NotFound.js")
    );
  let default = make;
};

[@react.component]
let make = () => {
  <React.Suspense fallback=React.null> <Lazy /> </React.Suspense>;
};
