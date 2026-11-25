#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
void loadLeaderboard(int board[5]);
void addScore(int board[5], int score);
void drawLeaderboard(RenderWindow& window, const Font& font, const int board[5]);
