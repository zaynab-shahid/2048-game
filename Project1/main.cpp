#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "movement.h"
#include "board.h"
#include "menu.h"
#include "theme.h"
#include<fstream>
#include "sound.h"
#include"howtoplay.h"

int getTimeLimit(int current_mode)
{
	if (current_mode == 0)
	{
		return -1;
	}
	else if (current_mode == 1)
	{
		return 600;
	}
	else if (current_mode == 2)
	{
		return 300;
	}
	else 
	{
		return 180;
	}
}

using namespace std;
using namespace sf;

int main()
{
	srand(time(0));
	int array[4][4] = {0};
	int score = 0;
	int highscore = 0;
	ifstream infile("highscore.txt");
	infile >> highscore;
	new_number(array);
	new_number(array);

	Font font;
	if (!font.openFromFile("Blue Winter.otf"))
	{
		return 0;
	}

	RenderWindow window(VideoMode({ 800, 950 }), "2048-Game", Style::Titlebar | Style::Close);
	GameState state = MENU;
	Clock gameClock;
	int timeLimit = 0;
	gameSound Sound;
	Sound.loadSounds();
	GameState previousState = state;
	bool hasTimeLimit = true;

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
			else if (state == MENU)
			{
				menuInput(*event, state);
				if (state == PLAYING)
				{
					timeLimit = getTimeLimit(current_mode);
					gameClock.restart();
				}
				if (const auto* mousePressed = event->getIf<Event::MouseButtonPressed>())
				{
					if(mousePressed->button == Mouse::Button::Left)
					{
						if(sound)
							Sound.playClickSound();
					}
				}
			}
			else if (state == PLAYING)
			{
				if (const auto* keyPressed = event->getIf<Event::KeyPressed>())
				{
					keys(*keyPressed, array, score, Sound , state);
					cout << "Score:" << score << endl;
				}
				boardInput(*event, window, state, score, array, timeLimit, gameClock);
			}
			else if (state == WIN)
			{
				winScreenInput(*event, window, state, score, array);
			}
			else if (state == LOSE)
			{
				loseScreenInput(*event, window, state, score, array);
			}
			else if (state == HOWTOPLAY)
			{
				howToPlayInput(*event, window, state);
				
			}
		
		}

		if (state == PLAYING && previousState != PLAYING)
		{
			timeLimit = getTimeLimit(current_mode);
			gameClock.restart();
		}
		previousState = state;

		int timeLeft = timeLimit - gameClock.getElapsedTime().asSeconds();
		if (score > highscore)
		{
			highscore = score;
			ofstream infile("highscore.txt");
			infile << highscore;
		}
		if (state == PLAYING && is_full(array))
		{
			state = LOSE;
		}
		if (state == PLAYING && timeLimit > 0 && timeLeft <=0)
		{
			state = LOSE;
		}
		Color bgColor = Color(255, 255, 224);
		if (current_theme == 1)
		{
			bgColor = Color(22, 24, 42);
		}
		else if (current_theme == 2)
		{
			bgColor = Color(235, 240, 228);
		}

		window.clear(bgColor);

		if (state == MENU)
		{
			drawMenu(window, font);
		}
		else if (state == PLAYING)
		{
			drawBoard(window, font, array, score, highscore, timeLeft, timeLimit);
		}
		else if (state == WIN)
		{
			winScreen(window, font, array, score, highscore);
		}
		else if (state == LOSE)
		{
			loseScreen(window, font, array, score, highscore);
		}
		if (state == HOWTOPLAY)
		{
			drawHowToPlay(window, font);
		}
		window.display();
	}
	return 0;
}