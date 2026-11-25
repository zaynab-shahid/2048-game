
# 2048

A C++ / SFML recreation of the classic 2048 puzzle game, built as a **Fundamental Programming Project**.

Slide the tiles, merge matching numbers, and try to reach the **2048** tile before the board fills up.

---

## Features

- **4 difficulty levels**: each level changes the challenge, including the board size and the time limit (for example, *Easy* is a 4x4 board with no time limit).
- **3 visual themes**: switch between themes (such as *Standard*) from the main menu or during a game.
- **Score and Best Score**: your current score is shown during play, and your best score is saved.
- **Leaderboard**: view top scores from the main menu.
- **How to Play screen**: in-game instructions for new players.
- **Sound toggle**: turn sound ON or OFF from the menu or during a game.
- **Win and Lose screens**: the game tells you when you win or when no moves are left.
- **Restart and Menu buttons**: restart a game or return to the main menu at any time.

---

## How to Play

**Goal:** Combine tiles with the same number to reach the 2048 tile.

**Controls**

| Action | Keys |
| --- | --- |
| Slide tiles | Arrow keys or `W` `A` `S` `D` |
| Start the game from the menu | `Enter` or click **Play** |
| Return to the menu from How to Play | `Esc` or click **Back** |

**Rules**

1. When two tiles with the same number touch, they merge into one tile with double the value.
2. After every move, a new tile (2 or 4) appears in an empty cell.
3. Each merge adds the new tile's value to your score.
4. The game ends when the board is full and no merges are possible.

---

## Difficulty Levels

The game has **4 difficulty levels**. Difficulty changes the grid size and the time limit, so higher levels are harder and more demanding. Pick your level from the main menu before pressing **Play**.

| Level | Description |
| --- | --- |
| Easy | 4x4 board, no time limit |
| Level 2 | *(fill in board size / time limit)* |
| Level 3 | *(fill in board size / time limit)* |
| Level 4 | *(fill in board size / time limit)* |

## Themes

The game comes with **3 themes** that change the colours of the board and tiles:

1. Standard
2. *(fill in theme name)*
3. *(fill in theme name)*

---

## Screenshots

Add your screenshots here, for example:

```
![Main Menu](screenshots/menu.png)
![Gameplay](screenshots/gameplay.png)
```

---

## Built With

- **C++**
- **[SFML 3](https://www.sfml-dev.org/)** (Simple and Fast Multimedia Library) for graphics, input, and audio

## Getting Started

### Requirements

- A C++17 (or newer) compiler, such as Visual Studio 2022
- SFML 3 installed and linked to your project

### Build and Run

1. Clone or download this repository.
2. Open the project in Visual Studio (or your preferred IDE).
3. Link the SFML libraries (Graphics, Window, System, Audio).
4. Make sure the `assets` folder (fonts, sounds, images) is in the project's working directory.
5. Build and run.

---

## Developers

This project was developed by:

- **Abreesham Kashif**
- **Zaynab Shahid**
- **Fatimah Hammad**

---

## License

This project was created for educational purposes. Fonts and other assets belong to their respective owners; please check their licenses before redistributing.

