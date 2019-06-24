open Utils;

[@react.component]
let make = () => {
  <div className="p-6 pb-16">
    "We're sorry. The page you are looking for could not be found. To go back home click "
    ->text
    <a
      className="text-blue-500 cursor-pointer hover:text-blue-400"
      onClick={_e => push("/")}>
      "here"->text
    </a>
    "."->text
  </div>;
};

let default = make;
