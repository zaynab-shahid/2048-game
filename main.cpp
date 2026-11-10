#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
using namespace std;
using namespace sf;
int main()
{
	
	int array[4][4] = {
		{ 2, 0, 0, 4 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	float x;
	float y;
	float step = 85 + 10;
	float gridSize = 4 * 85 + 3 * 10;
	float X = -55+(1000 - gridSize) / 2;
	float Y = -55+ (1000 - gridSize) / 2;
	Font font;
	if (!font.openFromFile("arial.ttf"))
	{
		return -1;
	}

	RenderWindow window(VideoMode({ 1000, 1000 }), "Random Title");
	RectangleShape rectangle({ 400,400 });
	RectangleShape box;
	Text text (font,"0",30);
	text.setFillColor(Color::Black);
	text.setPosition({ 250.f, 250.f });

	rectangle.setPosition({ 250.f, 250.f });

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
			window.clear(Color(187, 173, 160));
			window.draw(rectangle);
			for (int i = 0;i < 4;i++)
			{
				for (int j = 0;j < 4;j++)
				{

					x = X+ j * step;
					y = Y + i * step;
					box.setSize({ 85, 85 });
					box.setPosition({ x,y });
					box.setFillColor(Color::Cyan);
					window.draw(box);

					text.setString(to_string(array[i][j]));
					text.setPosition({ x + 30,y + 30 });
					window.draw(text);

				}
			}
		}
		
		
		window.display();
}	
	return 0;
}