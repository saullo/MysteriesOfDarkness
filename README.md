# Mysteries Of Darkness

Mysteries Of Darkness is a massively multiplayer online role-playing game written in C++ from scratch.

[![Build](https://github.com/saullo/MysteriesOfDarkness/actions/workflows/cmake.yml/badge.svg)](https://github.com/saullo/MysteriesOfDarkness/actions/workflows/cmake.yml)

![Screenshot](https://github.com/saullo/MysteriesOfDarkness/blob/main/Meta/Images/Screenshot-2022-07-27-235417.png?raw=true)
*The Game Editor*

## Build

The steps below take you to clone the repository, then compile and run all the tools and the game on your own:

### Windows

1. Install **Visual Studio 2022**.

   All desktop editions of Visual Studio 2022 can be used,
   including [Visual Studio Community 2022](https://visualstudio.microsoft.com/), which is free for small teams and
   individual developers. First install the following workloads: **Desktop Development with C++** and **Game Development
   with C++**. On the Individual Components tab at the top, also choose the following components:

    - **C++ Clang Compiler for Windows**
    - **C++ Clang-cl for v143 build tools**

1. Clone this repository using the `Open with Visual Studio` button.

   ![Screenshot](https://github.com/saullo/MysteriesOfDarkness/blob/main/Meta/Images/Screenshot-2022-07-27-142357.png?raw=true)

   *Learn more about at: [Contributing to projects](https://guides.github.com/activities/forking/)*

   If you prefer not to use Git, you can get the source with the **Download ZIP** button.

1. Set your configuration to **x64 Debug** and your build preset to **x64 Debug** and select **Editor.exe** for your
   startup item and click on it.

   ![Screenshot](https://github.com/saullo/MysteriesOfDarkness/blob/main/Meta/Images/Screenshot-2022-07-27-144237.png?raw=true)

   *Learn more about
   at: [Configure and build with CMake Presets in Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-presets-vs?view=msvc-170)*

1. After the build is complete, the selected startup item will run automatically and start debugging.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/) - GNU General Public License v3.0