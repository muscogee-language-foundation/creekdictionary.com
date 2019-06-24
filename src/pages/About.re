open Utils;

[@react.component]
let make = () => {
  <div className="p-6 pb-16 max-w-2xl mx-auto">
    <h1 className="text-6xl"> "About"->text </h1>
    <p className="mb-2">
      {(
         "The Muscogee (Creek) Dictionary is inteneded to be a companion for those who know the Muscogee (Creek) "
         ++ "alphabet, a few words, and who have access to fluent speakers. We hope using this app empowers you "
         ++ "to use the language more with friends and family."
       )
       ->text}
    </p>
    <p className="mb-2">
      {(
         "This project is a work in progress and we would appreciate any help from the community. "
         ++ "If you would like to make this project better head on over to the GitHub repository at "
       )
       ->text}
      <a
        className="text-blue-500 hover:text-blue-400"
        rel="noopener noreferrer"
        href="https://github.com/nativesintech/muscogee-creek-dictionary">
        "nativesintech/muscogee-creek-dictionary"->text
      </a>
      "."->text
    </p>
    <p className="mb-2">
      "The Muscogee (Creek) Dictionary is a project of Natives in Tech. Natives in Tech is a coalition of Native and non-Native developers whose mission is to empower Native peoples through software development."
      ->text
    </p>
    <p className="mb-2">
      "To learn more go to "->text
      <a
        rel="noopener noreferrer"
        target="_blank"
        className="text-blue-500 hover:text-blue-400"
        href="http://nativesintech.org">
        "nativesintech.org"->text
      </a>
      "."->text
    </p>
  </div>;
};

let default = make;
