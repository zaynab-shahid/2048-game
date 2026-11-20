#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "movement.h"
#include "board.h"
#include "color.h"

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

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<Event::KeyPressed>())
			{
				keys(*keyPressed, array);
			}
		}
		if (is_full(array))
		{
			break;
		}
		window.clear(Color(255, 255, 224));
		drawBoard(window, font, array);

		window.display();
	}
	return 0;
}