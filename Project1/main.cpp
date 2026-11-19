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
	float x = 0;
	float y = 0;
	float step = 85 + 10;
	float gridSize = 4 * 85 + 3 * 10;
	float X = (1000 - gridSize) / 2;
	float Y = (1000 - gridSize) / 2;
	Font font;
	if (!font.openFromFile("arial.ttf"))
	{
		return -1;
	}

	RenderWindow window(VideoMode({ 1000, 1000 }), "2048-Game");
	RectangleShape rectangle({ gridSize + 20, gridSize + 20 });
	RectangleShape box;
	Text text(font, "0", 30);

	rectangle.setPosition({ X - 10, Y - 10 });
	rectangle.setFillColor(Color(255, 218, 185));

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
				if (keyPressed->code == Keyboard::Key::Left)
				{
					left(array);
					new_number(array);
				}
				else if (keyPressed->code == Keyboard::Key::Right)
				{
					right(array);
					new_number(array);
				}
				else if (keyPressed->code == Keyboard::Key::Up)
				{
					top(array);
					new_number(array);
				}
				else if (keyPressed->code == Keyboard::Key::Down)
				{
					bottom(array);
					new_number(array);
				}
			}
		}
		if (is_full(array))
		{
			break;
		}
		window.clear(Color(255, 255, 224));
		window.draw(rectangle);
		for (int i = 0;i < 4;i++)
		{
			for (int j = 0;j < 4;j++)
			{
				x = X + j * step;
				y = Y + i * step;
				box.setSize({ 85, 85 });
				box.setPosition({ x,y });
				box.setFillColor(getTileColor(array[i][j]));
				window.draw(box);
				text.setString(to_string(array[i][j]));
				if (array[i][j] == 0)
				{
					text.setString("");
				}
				else
				{
					text.setString(to_string(array[i][j]));
				}
				if (array[i][j] > 1000)
				{
					text.setCharacterSize(22);
				}
				else if (array[i][j]>100)
				{
					text.setCharacterSize(24);
				}
				else
				{
					text.setCharacterSize(26);
				}
				if (array[i][j] == 0)
				{
					text.setFillColor(Color(205, 193, 180));
				}
				else
				{
					text.setFillColor(Color::Black);
				}

				FloatRect bounds = text.getLocalBounds();
				text.setOrigin({ bounds.position.x + bounds.size.x / 2.f,bounds.position.y + bounds.size.y / 2.f });
				text.setPosition({ x + 85 / 2.f, y + 85 / 2.f });

				window.draw(text);


			}

		}


		window.display();
	}

	return 0;
}


