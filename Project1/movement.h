#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

void left(int array[][4], int &score);
void right(int array[][4], int &score);
void top(int array[][4], int &score);
void bottom(int array[][4], int &score);
void keys(const Event::KeyPressed& keyPressed, int array[][4], int& score, Sound& moveSound, Sound& mergeSound);