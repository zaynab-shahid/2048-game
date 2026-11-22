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


	

	SoundBuffer moveBuffer,mergeBuffer,clickBuffer;
	Sound moveSound(moveBuffer);
	Sound mergeSound(mergeBuffer);
	Sound clickSound(clickBuffer);


	Font font;
	if (!font.openFromFile("arial.ttf"))
	{
		
		return -1;
	}

	RenderWindow window(VideoMode({ 1000, 1000 }), "2048-Game", Style::Titlebar | Style::Close);
	GameState state = MENU;
	Clock gameClock;
	int timeLimit = 0;
	gameSound Sound;
	Sound.loadSounds();

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
					gameClock.restart();
					if (current_mode == 0)
					{
						timeLimit = 180;
					}
					else if (current_mode == 1)
					{
						timeLimit = 120;
					}
					else if (current_mode == 2)
					{
						timeLimit = 90;
					}
					else
					{
						timeLimit = 60;
					}
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
					
					keys(*keyPressed, array, score, Sound );
					cout << "Score:" << score << endl;
				}
			}
		}
		int timeLeft = timeLimit - gameClock.getElapsedTime().asSeconds();
		if (score > highscore)
		{
			highscore = score;
			ofstream infile("highscore.txt");
			infile << highscore;
		}
		if (state == PLAYING && is_full(array))
		{
			break;
		}
		if (state == PLAYING && timeLeft<=0)
		{
			break;
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
			drawBoard(window, font, array, score, highscore, timeLeft);
		}
		window.display();
	}
	return 0;
}