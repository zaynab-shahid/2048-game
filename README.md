# 2048-game
Programming Fundamentals Semester Project - 2048 Game in SFML
# 2048 Game (C++ / SFML)

A desktop version of the classic **2048** puzzle game, written in C++ with [SFML 3](https://www.sfml-dev.org/). Slide the tiles around a 4x4 grid, merge matching numbers, and try to build the **2048** tile.



## Features

- 4x4 game board rendered with SFML
- Smooth keyboard controls with the arrow keys
- Tiles merge when two equal numbers collide
- A new tile (2) spawns in a random empty cell after every move
- Each tile value has its own color
- Game ends when the board is full

## Controls

| Key | Action |
|---|---|
| Up arrow | Slide tiles up |
| Down arrow | Slide tiles down |
| Left arrow | Slide tiles left |
| Right arrow | Slide tiles right |

Close the window to quit.

## How to Play

1. The game starts with two tiles on the board.
2. Press an arrow key and all tiles slide in that direction as far as they can.
3. When two tiles with the same number touch, they merge into one tile with double the value (2 + 2 = 4, 4 + 4 = 8, and so on).
4. After each move, a new tile appears in a random empty cell.
5. Keep merging to reach **2048**.

## Project Structure

```
2048-game/
└── Project1/
    ├── main.cpp        # Window, game loop, input handling, drawing
    ├── board.h / .cpp  # new_number() and is_full(): spawning tiles, checking the board
    ├── movement.h/.cpp # left(), right(), top(), bottom(): sliding and merging logic
    ├── color.h / .cpp  # getTileColor(): maps a tile value to a color
    ├── arial.ttf       # Font used to draw the numbers
    └── Project1.vcxproj
```

## Requirements

- A C++ compiler with C++17 support (MSVC, g++, or clang++)
- [SFML 3.x](https://www.sfml-dev.org/download.php) (the code uses the SFML 3 API)
- Visual Studio 2022 or later (optional, a project file is included)

## Building and Running

### Visual Studio

1. Clone the repository:
   ```
   git clone https://github.com/zaynab-shahid/2048-game.git
   ```
2. Install SFML 3 and make sure the project is linked against it (include directories, library directories, and the `sfml-graphics`, `sfml-window` and `sfml-system` libraries).
3. Open `Project1.slnx` in Visual Studio.
4. Build and run (`Ctrl + F5`).

### Command line (g++)

From the folder containing the source files:

```
g++ main.cpp board.cpp movement.cpp color.cpp -o 2048 -lsfml-graphics -lsfml-window -lsfml-system
```

Then run `./2048` (or `2048.exe` on Windows).

> **Important:** the game loads `arial.ttf` at startup. Make sure this file is in the same folder you run the program from, otherwise the game will exit immediately.


## Built With

- C++
- [SFML 3](https://www.sfml-dev.org/)
##Authered By
Abreesham Kashif
Zaynab Shahid
Fatima Hammad
