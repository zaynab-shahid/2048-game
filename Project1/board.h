#pragma once
#include <SFML/Graphics.hpp>
#include "menu.h"
using namespace sf;
bool Won(const int array[4][4]);
void new_number(int array[][4]);
bool Lost(const int array[][4]);
bool is_full(const int array[][4]);
void boardInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4], int& timeLimit, Clock& gameClock);
void drawBoard(RenderWindow& window, const Font& font, const int array[][4], int score,int highscore, int timeLeft, int timeLimit);
void winScreen(RenderWindow& window, const Font& font, const int array[][4], int score, int highscore);
void winScreenInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4]);
void loseScreen(RenderWindow& window, const Font& font, const int array[4][4], int score, int highscore);
void loseScreenInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4]);
void howToPlayInput(const Event& event, const RenderWindow& window, GameState& state);
void leaderboardInput(const Event& event, const RenderWindow& window, GameState& state);