open Utils;

[@react.component]
let make = () => {
  let (isNavbarOpen, setNavbar) = React.useState(() => false);

  <nav
    className="flex items-center justify-between flex-wrap bg-blue-500 p-6 relative ">
    <div
      onClick={_e => {
        push("/");
        setNavbar(_bool => false);
      }}
      className="flex items-center flex-shrink-0 text-white mr-6 cursor-pointer">
      "Muscogee (Creek) Dictionary"->text
    </div>
    <div className="block lg:hidden">
      <button
        onClick={_e => setNavbar(bool => !bool)}
        className="flex items-center px-3 py-2 border rounded text-blue-200 border-blue-400 hover:text-white hover:border-white">
        <svg
          className="fill-current h-3 w-3"
          viewBox="0 0 20 20"
          xmlns="http://www.w3.org/2000/svg">
          <title> "Menu"->text </title>
          <path d="M0 3h20v2H0V3zm0 6h20v2H0V9zm0 6h20v2H0v-2z" />
        </svg>
      </button>
    </div>
    <div
      style={
        isNavbarOpen
          ? ReactDOMRe.Style.make(~top="78px", ()) : ReactDOMRe.Style.make()
      }
      className={
        "w-full flex-grow lg:flex lg:items-center lg:w-auto "
        ++ (
          isNavbarOpen
            ? "block absolute z-10 w-full bg-blue-500 -m-6 pl-6 pb-6"
            : "hidden"
        )
      }>
      <div className="text-sm lg:flex-grow">
        <a
          onClick={_e => {
            push("/about");
            setNavbar(_bool => false);
          }}
          className="block mt-4 lg:inline-block lg:mt-0 text-blue-200 hover:text-white mr-4 cursor-pointer">
          "About"->text
        </a>
        <a
          onClick={_e => {
            push("/resources");
            setNavbar(_bool => false);
          }}
          className="block mt-4 lg:inline-block lg:mt-0 text-blue-200 hover:text-white mr-4 cursor-pointer lg:hidden hidden">
          "Resources"->text
        </a>
        <a
          onClick={_e => {
            push("/history");
            setNavbar(_bool => false);
          }}
          className="block mt-4 lg:inline-block lg:mt-0 text-blue-200 hover:text-white cursor-pointer lg:hidden hidden">
          "History"->text
        </a>
      </div>
    </div>
  </nav>;
};
