#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum GameState
{
	MENU,
	PLAYING,
<<<<<<< HEAD
	TRANSITION,
	HOWTOPLAY,
	LEADERBOARD
=======
	WIN,
	LOSE
>>>>>>> 3a5a4f3f5780e011e8c69923df95284ab6940c9f
};
extern int current_mode;
extern bool sound;

void menuInput(const Event& event, GameState& state);
void drawMenu(RenderWindow& window, const Font& font);
void drawHowToPlay(RenderWindow& window, const Font& font);
void centerText(Text& text, RectangleShape& button);
void drawLeaderboard(RenderWindow& window, const Font& font);