#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum GameState
{
	MENU,
	PLAYING
};

void menuInput(const Event& event, GameState& state);
void drawMenu(RenderWindow& window, const Font& font);