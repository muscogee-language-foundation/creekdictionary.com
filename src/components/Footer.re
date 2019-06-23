open Utils;

[@react.component]
let make = () => {
  <footer
    className="absolute bottom-0 w-full h-16 flex justify-center border-t pt-4">
    {j|Made with ❤️ by Natives in Tech|j}->text
  </footer>;
};
