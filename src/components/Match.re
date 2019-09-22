open Utils;

[@react.component]
let make = (~entry) => {
  <div
    key={entry.creek}
    className="w-full sm:w-auto shadow-lg p-4 rounded mb-2 border mr-2">
    <span className="uppercase text-2xl mr-2"> entry.creek->text </span>
    <span className="text-gray-500 lowercase"> entry.english->text </span>
    <div>
      {Belt.Array.map(Js.String.split(",", entry.tags), tag =>
         <span
           className="bg-gray-500 rounded-full mr-1 text-white py-1 px-2 text-xs hover:shadow-md lowercase">
           {j|#$tag|j}->text
         </span>
       )
       ->React.array}
    </div>
  </div>;
};
