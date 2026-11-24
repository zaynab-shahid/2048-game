#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum GameState
{
	MENU,
	PLAYING,
	TRANSITION
};
extern int current_mode;
extern bool sound;

void menuInput(const Event& event, GameState& state);
void drawMenu(RenderWindow& window, const Font& font);