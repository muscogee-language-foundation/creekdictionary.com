const express = require("express");
const React = require("react");
const ReactDOMServer = require("react-dom/server");
const emotionServer = require("emotion-server");
const path = require("path");

const { make } = require("../lib/js/src/App");
const asset = require("../dist/manifest.json");
const App = make;

const server = express();

server
  .disable("x-powered-by")
  .use("/assets", express.static(path.join(__dirname, "../dist")))
  .get("/*", (req, res) => {
    const html = emotionServer.renderStylesToString(
      ReactDOMServer.renderToString(React.createElement(App))
    );

    res.send(`
      <!DOCTYPE html>
      <html lang="">
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>ReasonReact SSR Starter</title>
        <link ref="stylesheet" href="/assets/${asset["main.css"]}">
        <script src="/assets/${asset["main.js"]}" defer></script>
        <body>
          <div id="root">${html}</div>
        </body>
      </html>
    `);
  })
  .listen(3000, () => {
    console.log("Server listening on port 3000");
  });
