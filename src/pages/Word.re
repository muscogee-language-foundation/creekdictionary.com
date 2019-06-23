open Utils;

[@react.component]
let make = (~id) => {
  <div> {j|Word $id|j}->text </div>;
};
