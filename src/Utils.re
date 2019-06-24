let rawData = [%raw "require(\"../../../src/words.js\").default"];

type entry = {
  english: string,
  creek: string,
  meaning: string,
  tags: string,
};

type entries = array(entry);

module Decode = {
  let decodeEntry = json =>
    Json.Decode.{
      english: json |> field("english", string),
      creek: json |> field("creek", string),
      meaning: json |> field("meaning", string),
      tags: json |> field("tags", string),
    };

  let decodeEntries = Json.Decode.(array(decodeEntry));
};

let data = rawData |> Json.parseOrRaise |> Decode.decodeEntries;

let text = React.string;

let not = bool => !bool;

let never = _bool => false;

let push = ReasonReact.Router.push;

[@bs.val] external encodeURIComponent: string => string = "";
[@bs.val] external decodeURIComponent: string => string = "";
