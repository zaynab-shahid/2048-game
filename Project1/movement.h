#pragma once
#include <SFML/Graphics.hpp>
#include"sound.h"
using namespace sf;

void left(int array[][4], int &score, GameState& state);
void right(int array[][4], int &score, GameState& state);
void top(int array[][4], int &score, GameState& state);
void bottom(int array[][4], int &score, GameState& state);
void keys(const Event::KeyPressed& keyPressed, int array[][4], int& score, gameSound& Sound, GameState& state);