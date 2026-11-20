#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "movement.h"
#include "board.h"
#include "color.h"
#include "menu.h"
#include "theme.h"

using namespace std;
using namespace sf;


int main()
{
	srand(time(0));
	int array[4][4] = {0};

	new_number(array);
	new_number(array);
	
	Font font;
	if (!font.openFromFile("arial.ttf"))
	{
		return -1;
	}

	RenderWindow window(VideoMode({ 1000, 1000 }), "2048-Game");
	GameState state = MENU;

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
			}
			else if (state == PLAYING)
			{
				if (const auto* keyPressed = event->getIf<Event::KeyPressed>())
				{
					keys(*keyPressed, array);
				}
			}
		}
		if (state == PLAYING && is_full(array))
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
			drawBoard(window, font, array);
		}

		window.display();
	}
	return 0;
}