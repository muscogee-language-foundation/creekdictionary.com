import React from "react";
import ReactDOM from "react-dom";
import "./global.css";
import App from "../lib/js/src/App";

ReactDOM.render(<App />, document.querySelector("#root"));

if (process.env.NODE_ENV === "production" && "serviceWorker" in navigator) {
  window.addEventListener("load", function() {
    navigator.serviceWorker.register("dist/service-worker.js");
  });
}
