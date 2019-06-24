const words = [
  {
    english: "bird",
    creek: "fuswv",
    meaning: "bird",
    tags: "animal,clan,bird"
  },
  {
    english: "bear",
    creek: "nokose",
    meaning: "bear",
    tags: "animal,clan,bear"
  },
  { english: "white", creek: "hvtke", meaning: "white", tags: "color" },
  { english: "black", creek: "lvste", meaning: "black", tags: "color" }
];

const json = JSON.stringify(words);

exports.default = json;
