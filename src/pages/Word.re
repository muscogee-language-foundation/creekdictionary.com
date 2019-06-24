open Utils;

[@react.component]
let make = (~id) => {
  <div className="pb-16"> {j|Word $id|j}->text </div>;
};
