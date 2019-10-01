const { CleanWebpackPlugin } = require("clean-webpack-plugin");
const Dotenv = require("dotenv-webpack");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const path = require("path");

module.exports = {
  // The file that is the main point of access for the SPA
  entry: path.join(__dirname, "../src/client.js"),
  // Where you want to output the file
  output: {
    // The output file's name
    filename: "bundle.js",
    // Where the output JavaScript bundle will go
    path: path.join(__dirname, "../dist")
  },
  // The mode to determine what optimizations to make
  mode: "development",
  // The source map tool to see where errors occur in your editor
  devtool: "cheap-module-source-map",
  // The loaders which handle how to compile which files
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /(node_modules)/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env", "@babel/preset-react"],
            plugins: ["@babel/plugin-syntax-dynamic-import"]
          }
        }
      },
      {
        test: /\.css$/,
        use: [
          { loader: "style-loader" },
          { loader: "css-loader", options: { importLoaders: 1 } },
          { loader: "postcss-loader" }
        ]
      },
      {
        test: /\.html$/,
        use: [
          {
            loader: "html-loader"
          }
        ]
      }
    ]
  },
  stats: "minimal",
  plugins: [
    new Dotenv({
      path: "./.env.dev",
      safe: true
    }),
    // Plugin to clean the build folder on every build
    new CleanWebpackPlugin(),
    // Plugin to create the index.html file and inject the script which
    // points to the JavaScript bundle
    new HtmlWebpackPlugin({
      template: path.join(__dirname, "../src/index.html"),
      filename: "index.html"
    })
  ],
  // The development server
  devServer: {
    // The path to the output folder to serve
    contentBase: path.join(__dirname, "../dist"),
    // Fallback to index.html on 404s
    historyApiFallback: true,
    // Enable gzip compression
    compress: true,
    // Declare the port to serve the files
    port: 3000
  }
};
