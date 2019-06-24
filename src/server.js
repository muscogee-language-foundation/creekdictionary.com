const express = require("express");
const React = require("react");
const ReactDOMServer = require("react-dom/server");
const path = require("path");

const { make } = require("../lib/js/src/App");
const {
  assetsByChunkName: { main, styles }
} = require("../dist/stats.json");

const App = make;

const server = express();

server
  .disable("x-powered-by")
  .use("/assets", express.static(path.join(__dirname, "../dist")))
  .get("/*", (_req, res) => {
    const html = ReactDOMServer.renderToString(React.createElement(App));

    res.send(`
      <!DOCTYPE html>
      <html lang="en">
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Muscogee (Creek) Dictionary</title>

        <meta
          name="description"
          content="Muscogee (CreeK) Dictionary is a web app to make it easier to search for the meaning of Muscogee (Creek) words."
        />

        <meta
          name="twitter:card"
          value="Muscogee (CreeK) Dictionary is a web app to make it easier to search for the meaning of Muscogee (Creek) words."
        />

        <meta property="og:title" content="Muscogee (Creek) Dictionary" />
        <meta property="og:type" content="website" />
        <meta property="og:url" content="https://creekdictionary.com" />
        <meta
          property="og:description"
          content="Muscogee (CreeK) Dictionary is a web app to make it easier to search for the meaning of Muscogee (Creek) words."
        />

        <link rel="stylesheet" href="/assets/${styles[0]}">
        <script src="/assets/${main}" defer></script>
        <script src="/assets/${styles[1]}" defer></script>
        <body>
          <div id="root">${html}</div>
        </body>
      </html>
    `);
  })
  .listen(3000, () => {
    console.log("Server listening on port 3000");
  });
