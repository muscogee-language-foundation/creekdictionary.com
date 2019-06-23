open Utils;

[@react.component]
let make = () => {
  <div className="p-6 max-w-2xl mx-auto">
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
      "The Muscogee (Creek) Dictionary is a project of Natives in Tech. Natives in Tech is a coalition of Native and non-Native developers whose mission is to empower Native peoples through software development."
      ->text
    </p>
    <p>
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
