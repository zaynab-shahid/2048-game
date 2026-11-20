#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

void left(int array[][4]);
void right(int array[][4]);
void top(int array[][4]);
void bottom(int array[][4]);
void keys(const Event::KeyPressed& keyPressed, int array[][4]);