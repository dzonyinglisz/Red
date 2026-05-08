# PKNwZST / FNaZST - documentation
This is the documentation file for this project talking about how certain things are implemented, etc.

### DEPENDENCIES:
This project uses [Raylib](https://github.com/raysan5/raylib) for displaying the window, essential types, etc. and [RayGUI](https://github.com/raysan5/raygui) which is a simple imediate mode GUI library for Raylib based projects providing a simple way to quickly implement debug UI.

### STRUCTURE:
This project is structured like so:

| NAME   | DESCRIPTION                                                          |
| ------ | -------------------------------------------------------------------- |
| PC     |                                                                      |
| RAYLIB | C library we use as a base for this custom engine                    |
| ENGINE | C++ class used as a way to communicate with the Engine functionality |
| GAME   | This is where the game implementation resides                        |
| USER   | Despite everything it's still you                                    |

Where the `GAME` segment gets split into custom classes like Entities and other game mechanics.
