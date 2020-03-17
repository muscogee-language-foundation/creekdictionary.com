open Utils;

[@react.component]
let make = (~entry) => {
  <div className="w-full sm:w-auto shadow-lg p-4 rounded mb-2 border mr-2">
    <div className="uppercase text-2xl mr-2 break-words">
      entry.creek->text
    </div>
    <div className="text-gray-500 lowercase break-words">
      entry.english->text
    </div>
  </div>;
};
