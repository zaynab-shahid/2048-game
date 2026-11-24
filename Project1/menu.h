#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum GameState
{
	MENU,
	PLAYING,
	TRANSITION,
	HOWTOPLAY,
	LEADERBOARD
};
extern int current_mode;
extern bool sound;

void menuInput(const Event& event, GameState& state);
void drawMenu(RenderWindow& window, const Font& font);
void drawHowToPlay(RenderWindow& window, const Font& font);
void centerText(Text& text, RectangleShape& button);
void drawLeaderboard(RenderWindow& window, const Font& font);