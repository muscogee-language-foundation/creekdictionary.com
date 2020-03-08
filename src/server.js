const express = require("express");
const React = require("react");
const ReactDOMServer = require("react-dom/server");
const path = require("path");
const prerender = require("prerender-node");

const { make } = require("../lib/js/src/App");
const {
  assetsByChunkName: { main, styles }
} = require("../dist/stats.json");

const App = make;

const server = express();

server
  .disable("x-powered-by")
  .use(
    "/assets",
    express.static(path.join(__dirname, "../dist"), { maxAge: "30d" })
  )
  .use(
    "/public",
    express.static(path.join(__dirname, "../public"), { maxAge: "30d" })
  )
  .use(prerender)
  .get("/*", (_req, res) => {
    const html = ReactDOMServer.renderToString(React.createElement(App));

    res.send(`
      <!DOCTYPE html>
      <html lang="en">
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="theme-color" content="#4299e1" />

        <link rel="apple-touch-icon" sizes="180x180" href="/public/apple-touch-icon.png" />
        <link rel="icon" type="image/png" sizes="32x32" href="/public/favicon-32x32.png" />
        <link rel="icon" type="image/png" sizes="16x16" href="/public/favicon-16x16.png" />
        <link rel="manifest" href="/public/site.webmanifest" />

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
