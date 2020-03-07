[@bs.val] external encodeURIComponent: string => string = "encodeURIComponent";
[@bs.val] external decodeURIComponent: string => string = "decodeURIComponent";
[@bs.val] external apiUrl: string = "process.env.API_URL";

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

let extractQuery = query => {
  Js.String.split("=", query)
  ->Belt.Array.get(1)
  ->Belt.Option.getWithDefault("");
};

let toLocaleLowerAndTrim = s => {
  s |> Js.String.toLocaleLowerCase |> Js.String.trim;
};

let includesCaseInsensitive = (~target, ~search) => {
  let s = search |> toLocaleLowerAndTrim |> decodeURIComponent;
  let t = target |> toLocaleLowerAndTrim;
  Js.String.includes(s, t);
};

let find = (search, entries) => {
  Belt.Array.keep(entries, (entry: entry) =>
    includesCaseInsensitive(~target=entry.creek, ~search)
    || includesCaseInsensitive(~target=entry.english, ~search)
  );
};
