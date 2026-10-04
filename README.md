# Remnant Library
Game engine for the Game Boy Advance built on top of the [butano](https://github.com/GValiente/butano) library.
(Currently in)capable of top-down action RPG, side-scrolling platformer and visual novel functionality.
Used in [Minigame Investigator](https://github.com/JK0JK/minigame-investigator). In a way this is a way to make the project's core open-source without fear of copyright infringement.

# Dependencies
This project automatically fetches [butano](https://github.com/GValiente/butano).
This project depends on and does not automatically install:
- Python
- devkitARM
Please refer back to [butano's installation process](https://gvaliente.github.io/butano/getting_started.html) before proceeding.

# Usage
This is incomplete, don't use it.
Either way, the setup starts with:
```
git clone https://github.com/JK0JK/remnant-engine
python setup.py
```
After which you will copy the structure of something like the stuff in `/examples/`.

In order to compile, simply
```
make -j"$(nproc)"
```

**IMPORTANT:** After enabling/disabling plugins, you must **ALWAYS** `make clean` before `make`ing to avoid stale implementations.

# License
This project is under the [zlib License](./LICENSE). This means that you can do anything so long as you never claim you wrote Remnant Engine.
Unless you use a custom engine that fully replaces Butano, you are subject to the licenses of both [Butano](https://github.com/GValiente/butano) and all of the projects it borrows from.
For the most part, this just requires that your project (which should be including remnant-engine anyway) includes the licenses present in the [licenses](licenses) folder and give credit in your project.

As soon as this project provides ways to add arbitrary text (i.e. for dialogue), so too will there be a section for credits that includes all of them.

# Contact
You can no longer find me on discord.
Now you can only email me at [thejkgameplays@proton.me](mailto:thejkgameplays@proton.me).

