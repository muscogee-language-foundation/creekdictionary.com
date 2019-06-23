const path = require("path");
const glob = require("glob");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const OptimizeCSSAssetsPlugin = require("optimize-css-assets-webpack-plugin");
const { CleanWebpackPlugin } = require("clean-webpack-plugin");
const ManifestPlugin = require("webpack-manifest-plugin");
const TerserPlugin = require("terser-webpack-plugin");
const PurgecssPlugin = require("purgecss-webpack-plugin");
const { StatsWriterPlugin } = require("webpack-stats-plugin");

module.exports = {
  entry: path.join(__dirname, "../src/client.js"),
  output: {
    filename: "[name].[hash].js",
    path: path.join(__dirname, "../dist"),
    publicPath: "/assets/"
  },
  mode: "production",
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
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
        use: [MiniCssExtractPlugin.loader, "css-loader", "postcss-loader"]
      }
    ]
  },
  plugins: [
    new CleanWebpackPlugin(),
    new MiniCssExtractPlugin({
      filename: "[name].[hash].css",
      chunkFilename: "[id].[hash].css"
    }),
    new PurgecssPlugin({
      paths: glob.sync(`./lib/js/src/**/*`, {
        nodir: true
      }),
      whitelist: ["html", "body"],
      extractors: [
        {
          extractor: content => content.match(/[A-Za-z0-9-_:/]+/g) || [],
          extensions: ["js", "html"]
        }
      ],
      rejected: true
    }),
    new ManifestPlugin(),
    new StatsWriterPlugin({
      filename: "stats.json"
    })
  ],
  optimization: {
    minimizer: [new TerserPlugin(), new OptimizeCSSAssetsPlugin()],
    splitChunks: {
      cacheGroups: {
        styles: {
          name: "styles",
          test: /\.css$/,
          chunks: "all",
          enforce: true
        }
      }
    }
  }
};
