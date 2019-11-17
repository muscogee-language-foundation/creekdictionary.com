open Utils;

[@react.component]
let make = (entry: entry) => {
  <div>
    {Belt.Array.map(Js.String.split(",", entry.tags), tag =>
       <span
         className="bg-gray-500 rounded-full mr-1 text-white py-1 px-2 text-xs hover:shadow-md lowercase">
         {j|#$tag|j}->text
       </span>
     )
     ->React.array}
  </div>;
};
