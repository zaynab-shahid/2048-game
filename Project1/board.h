#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
void new_number(int array[][4]);
bool is_full(int array[][4]);
void drawBoard(RenderWindow& window, const Font& font, const int array[][4], int score,int highscore );