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
  { english: "black", creek: "lvste", meaning: "black", tags: "color" },
  { english: "man", creek: "honvnwv", meaning: "man", tags: "people" },
  { english: "woman", creek: "hokte", meaning: "woman", tags: "people" },
  { english: "boy", creek: "cepane", meaning: "boy", tags: "people" },
  { english: "girl", creek: "hoktuce", meaning: "girl", tags: "people" },
  { english: "child", creek: "estuce", meaning: "child", tags: "people" },
  { english: "baby", creek: "pipuce", meaning: "baby", tags: "people" },
  {
    english: "old man",
    creek: "este vcule",
    meaning: "old man",
    tags: "people"
  },
  {
    english: "old woman",
    creek: "hoktvle",
    meaning: "old woman",
    tags: "people"
  },
  {
    english: "married man",
    creek: "honvnwv ehicv",
    meaning: "married man",
    tags: "people"
  },
  {
    english: "married woman",
    creek: "hokte ehesse",
    meaning: "married woman",
    tags: "people"
  },
  {
    english: "one",
    creek: "hvmken",
    meaning: "the number one",
    tags: "number"
  },
  {
    english: "two",
    creek: "hokkolen",
    meaning: "the number two",
    tags: "number"
  },
  {
    english: "three",
    creek: "tutcenen",
    meaning: "the number three",
    tags: "number"
  },
  {
    english: "four",
    creek: "osten",
    meaning: "the number four",
    tags: "number"
  },
  {
    english: "five",
    creek: "cvhkepen",
    meaning: "the number five",
    tags: "number"
  },
  {
    english: "six",
    creek: "epaken",
    meaning: "the number six",
    tags: "number"
  },
  {
    english: "seven",
    creek: "kolvpaken",
    meaning: "the number seven",
    tags: "number"
  },
  {
    english: "eight",
    creek: "cenvpaken",
    meaning: "the number eight",
    tags: "number"
  },
  {
    english: "nine",
    creek: "ostvpaken",
    meaning: "the number nine",
    tags: "number"
  },
  {
    english: "ten",
    creek: "palen",
    meaning: "the number ten",
    tags: "number"
  },
  {
    english: "cow",
    creek: "wakv",
    meaning: "cow",
    tags: "animal"
  },
  {
    english: "horse",
    creek: "rakko",
    meaning: "horse",
    tags: "animal"
  },
  {
    english: "dog",
    creek: "efv",
    meaning: "dog",
    tags: "animal"
  },
  {
    english: "cat",
    creek: "pose",
    meaning: "cat",
    tags: "animal"
  },
  {
    english: "pig",
    creek: "sokhv",
    meaning: "pig",
    tags: "animal"
  },
  {
    english: "chicken",
    creek: "tolose",
    meaning: "chicken",
    tags: "animal"
  },
  {
    english: "goose",
    creek: "sasvkwv",
    meaning: "goose",
    tags: "animal"
  },
  {
    english: "mouse",
    creek: "cesse",
    meaning: "mouse",
    tags: "animal"
  },
  {
    english: "fish",
    creek: "rvro",
    meaning: "fish",
    tags: "animal"
  },
  {
    english: "deer",
    creek: "eco",
    meaning: "deer",
    tags: "animal,clan"
  },
  {
    english: "alligator",
    creek: "hvlpvtv",
    meaning: "alligator",
    tags: "animal,clan"
  },
  {
    english: "tiger",
    creek: "kaccv",
    meaning: "tiger",
    tags: "animal,clan"
  },
  {
    english: "racoon",
    creek: "wotko",
    meaning: "racoon",
    tags: "animal,clan"
  },
  {
    english: "beaver",
    creek: "ecaswv",
    meaning: "beaver",
    tags: "animal,clan"
  },
  {
    english: "tree",
    creek: "eto",
    meaning: "tree",
    tags: "nature"
  },
  {
    english: "bush",
    creek: "stvpokhe",
    meaning: "bush",
    tags: "nature"
  },
  {
    english: "hill",
    creek: "ekvnhvlwuce",
    meaning: "hill",
    tags: "nature"
  },
  {
    english: "river",
    creek: "hvcce",
    meaning: "river",
    tags: "nature"
  },
  {
    english: "stream",
    creek: "hvccuce",
    meaning: "stream",
    tags: "nature"
  },
  {
    english: "water",
    creek: "owv (or wewv, uewv)",
    meaning: "water",
    tags: "nature,food"
  },
  {
    english: "rain",
    creek: "oske",
    meaning: "rain",
    tags: "nature"
  },
  {
    english: "sun",
    creek: "hvse",
    meaning: "sun",
    tags: "nature"
  },
  {
    english: "cloud",
    creek: "vholoce",
    meaning: "cloud",
    tags: "nature"
  },
  {
    english: "wind",
    creek: "hotvle",
    meaning: "wind",
    tags: "nature"
  },
  {
    english: "sky",
    creek: "sotv",
    meaning: "sky",
    tags: "nature"
  },
  {
    english: "grass",
    creek: "pvhe",
    meaning: "grass",
    tags: "nature"
  },
  {
    english: "big",
    creek: "rakke",
    meaning: "big",
    tags: "adjective"
  },
  {
    english: "short",
    creek: "cutkose",
    meaning: "short",
    tags: "adjective"
  },
  {
    english: "thick",
    creek: "cekfe",
    meaning: "thick",
    tags: "adjective"
  },
  {
    english: "thin",
    creek: "tvskoce",
    meaning: "thin",
    tags: "adjective"
  },
  {
    english: "thin (person)",
    creek: "hotosose",
    meaning: "thin (person)",
    tags: "adjective"
  },
  {
    english: "tall",
    creek: "mahe",
    meaning: "tall",
    tags: "adjective"
  },
  {
    english: "short",
    creek: "kocokne",
    meaning: "short",
    tags: "adjective"
  },
  {
    english: "loud",
    creek: "pokhe",
    meaning: "loud",
    tags: "adjective"
  },
  {
    english: "quiet",
    creek: "cvyayvke",
    meaning: "quiet",
    tags: "adjective"
  },
  {
    english: "fast",
    creek: "pvfne",
    meaning: "fast",
    tags: "adjective"
  },
  {
    english: "slow",
    creek: "hvlvlatke",
    meaning: "slow",
    tags: "adjective"
  },
  {
    english: "wide",
    creek: "tvphe",
    meaning: "wide",
    tags: "adjective"
  },
  {
    english: "kind",
    creek: "lopice",
    meaning: "kind",
    tags: "adjective"
  },
  {
    english: "mean",
    creek: "holwvyece",
    meaning: "mean",
    tags: "adjective"
  },
  {
    english: "heavy",
    creek: "honne",
    meaning: "heavy",
    tags: "adjective"
  },
  {
    english: "light (weight)",
    creek: "tvhokne",
    meaning: "light",
    tags: "adjective"
  },
  {
    english: "hot",
    creek: "hiye",
    meaning: "hot",
    tags: "adjective"
  },
  {
    english: "cold",
    creek: "kvsvppe",
    meaning: "cold",
    tags: "adjective"
  },
  {
    english: "deep (water)",
    creek: "lvoke",
    meaning: "deep",
    tags: "adjective"
  },
  {
    english: "cahke",
    creek: "shallow",
    meaning: "cahke",
    tags: "adjective"
  },
  {
    english: "strong",
    creek: "yekce",
    meaning: "strong",
    tags: "adjective"
  },
  {
    english: "weak",
    creek: "lowake",
    meaning: "weak",
    tags: "adjective"
  },
  {
    english: "fat",
    creek: "nehe",
    meaning: "fat",
    tags: "adjective"
  },
  {
    english: "tired",
    creek: "hotose",
    meaning: "tired",
    tags: "adjective"
  },
  {
    english: "sad",
    creek: "feknokke",
    meaning: "sad",
    tags: "adjective"
  },
  {
    english: "happy",
    creek: "afvcke",
    meaning: "happy",
    tags: "adjective"
  },
  {
    english: "good",
    creek: "henre",
    meaning: "good",
    tags: "adjective"
  },
  {
    english: "bad",
    creek: "holwvke",
    meaning: "bad",
    tags: "adjective"
  },
  {
    english: "food",
    creek: "hompetv",
    meaning: "food",
    tags: "adjective"
  },
  {
    english: "meal",
    creek: "hompetv hakv",
    meaning: "meal",
    tags: "adjective"
  },
  {
    english: "meat",
    creek: "vpeswv",
    meaning: "meat",
    tags: "adjective"
  },
  {
    english: "beef",
    creek: "wakvpeswv",
    meaning: "beef",
    tags: "adjective"
  },
  {
    english: "pork",
    creek: "sokhvpeswv",
    meaning: "pork",
    tags: "adjective"
  },
  {
    english: "salt pork",
    creek: "tosenv",
    meaning: "salt pork",
    tags: "adjective"
  },
  {
    english: "bread",
    creek: "tvklike",
    meaning: "bread",
    tags: "adjective"
  },
  {
    english: "sour corn bread",
    creek: "vce tvklik kvmokse",
    meaning: "sour corn bread",
    tags: "adjective"
  },
  {
    english: "blue bread",
    creek: "cvtvhakv",
    meaning: "blue bread",
    tags: "adjective"
  },
  {
    english: "fry bread",
    creek: "tvklik svkmorke",
    meaning: "fry bread",
    tags: "adjective"
  },
  {
    english: "milk",
    creek: "wakvpesse",
    meaning: "milk",
    tags: "adjective"
  },
  {
    english: "butter",
    creek: "wakvpesse neha",
    meaning: "butter",
    tags: "adjective"
  },
  {
    english: "coffee",
    creek: "kafe",
    meaning: "coffee",
    tags: "adjective"
  },
  {
    english: "tea",
    creek: "vsse",
    meaning: "tea",
    tags: "adjective"
  },
  {
    english: "corn",
    creek: "vce",
    meaning: "corn",
    tags: "adjective"
  },
  {
    english: "flour",
    creek: "hockvte",
    meaning: "flour",
    tags: "adjective"
  },
  {
    english: "sugar",
    creek: "vsokolv",
    meaning: "sugar",
    tags: "adjective"
  },
  {
    english: "salt",
    creek: "okcvnwv",
    meaning: "salt",
    tags: "adjective"
  },
  {
    english: "black pepper",
    creek: "homuce",
    meaning: "black pepper",
    tags: "adjective"
  },
  {
    english: "black pepper",
    creek: "homuce",
    meaning: "black pepper",
    tags: "adjective"
  }
];

const json = JSON.stringify(words);

exports.default = json;
