[@bs.val] external encodeURIComponent: string => string = "encodeURIComponent";
[@bs.val] external decodeURIComponent: string => string = "decodeURIComponent";
[@bs.val] external apiUrl: string = "process.env.API_URL";

let (<<) = Relude.Function.Infix.(<<);

type entry = {
  english: string,
  creek: string,
  meaning: string,
  tags: string,
};

type entries = {data: array(entry)};

module Decode = {
  let decodeEntry = json =>
    Json.Decode.{
      creek: json |> field("creek_word", string),
      english: json |> field("english_word", string),
      meaning: json |> field("english_definition", string),
      tags: json |> field("tags", string),
    };

  let decodeEntries = json =>
    Json.Decode.{data: json |> field("data", array(decodeEntry))};
};

let text = React.string;

let not = bool => !bool;

let never = _bool => false;

let push = ReasonReact.Router.push;

let replace = ReasonReact.Router.replace;

let extractQuery =
  Relude.Option.getOrElse("")
  << Relude.Array.at(1)
  << Relude.String.splitArray(~delimiter="=");

let toLocaleLowerAndTrim = s => {
  s |> Js.String.toLocaleLowerCase |> Js.String.trim;
};

let includesCaseInsensitive = (~target, ~search) => {
  let s = search |> toLocaleLowerAndTrim |> decodeURIComponent;
  let t = target |> toLocaleLowerAndTrim;
  Relude.String.contains(~search=s, t);
};
