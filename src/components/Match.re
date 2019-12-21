open Utils;

[@react.component]
let make = (~entry) => {
  <div
    className="w-full sm:w-auto shadow-lg p-4 rounded mb-2 border mr-2">
    <span className="uppercase text-2xl mr-2"> entry.creek->text </span>
    <span className="text-gray-500 lowercase"> entry.english->text </span>
  </div>;
};
