#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>

using namespace std;
using namespace sf;

void right(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		while (count < 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (array[i][j + 1] == 0)
				{
					array[i][j + 1] = array[i][j];
					array[i][j] = 0;
				}
			} // shifts everything to the right, no merging
			count++;
		}

		for (int j = 3; j >= 1; j--)
		{
			if (array[i][j - 1] == array[i][j])
			{
				array[i][j] = array[i][j] * 2;
				array[i][j - 1] = 0;
			}
		} // combining / merging the values

		for (int j = 0; j < 3; j++)
		{
			if (array[i][j + 1] == 0)
			{
				array[i][j + 1] = array[i][j];
				array[i][j] = 0;
			}
		} // rearranging after merging
	}

}

void left(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		while (count < 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (array[i][j] == 0)
				{
					array[i][j] = array[i][j + 1];
					array[i][j + 1] = 0;
				}
			} // arranging tiles
			count++;
		}

		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] == array[i][j + 1])
			{
				array[i][j] = array[i][j] * 2;
				array[i][j + 1] = 0;
			}
		} // merging tiles

		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] == 0)
			{
				array[i][j] = array[i][j + 1];
				array[i][j + 1] = 0;
			}
		} // rearranging merged tiles
	}
}

void top(int array[][4])
{
	for (int i = 0; i < 4; i++) //i here is columns
	{
		int count = 0;
		while (count < 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (array[j][i] == 0)
				{
					array[j][i] = array[j + 1][i];
					array[j + 1][i] = 0;
				}
			} // initial arrangement
			count++;
		}

		for (int j = 0; j < 3; j++)
		{
			if (array[j][i] == array[j + 1][i])
			{
				array[j][i] = array[j][i] * 2;
				array[j + 1][i] = 0;
			}
		} // merging tiles

		for (int j = 0; j < 3; j++)
		{
			if (array[j][i] == 0)
			{
				array[j][i] = array[j + 1][i];
				array[j + 1][i] = 0;
			}
		} // rearranging merged tiles
	}
}

void bottom(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		while (count < 2)
		{
			for (int j = 2; j >= 0; j--)
			{
				if (array[j +1][i] == 0)
				{
					array[j + 1][i] = array[j][i];
					array[j][i] = 0;
				}
			} //arranging initially
			count++;
		}

		for (int j = 2; j >= 0; j--)
		{
			if (array[j + 1][i] == array[j][i])
			{
				array[j + 1][i] = array[j + 1][i] * 2;
				array[j][i] = 0;
			}
		} // merging cells

		for (int j = 2; j >= 0; j--)
		{
			if (array[j + 1][i] == 0)
			{
				array[j + 1][i] = array[j][i];
				array[j][i] = 0;
			}
		}// final time rearranging merged cells
	}
}

	int main()
	{
		int array[4][4] = {0};
		float x;
		float y;
		float step = 85 + 10;
		float gridSize = 4 * 85 + 3 * 10;
		float X = -55 + (1000 - gridSize) / 2;
		float Y = -55 + (1000 - gridSize) / 2;
		Font font;
		if (!font.openFromFile("arial.ttf"))
		{
			return -1;
		}



		RenderWindow window(VideoMode({ 1000, 1000 }), "Random Title");
		RectangleShape rectangle({ 400,400 });
		RectangleShape box;
		Text text(font, "0", 30);
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

						x = X + j * step;
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