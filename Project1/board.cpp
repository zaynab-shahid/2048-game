#include"board.h"
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <string>
#include "color.h"
#include"theme.h"
using namespace sf;
using namespace std;

void new_number(int array[][4])
{
	int space = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == 0)
			{
				space++;
			}
		}
	}
	if (space == 0)
	{
		return;
	}

	while (true)
	{
		int x = rand() % 4;
		int y = rand() % 4;
		if (array[x][y] == 0)
		{
			array[x][y] = (rand() % 10 < 8) ? 2 : 4;
			return;
		}
	}
}
bool is_full(int array[][4])
{
	for (int x = 0; x < 4;++x)
	{
		for (int y = 0;y < 4;++y)
		{
			if (array[x][y] == 0)
			{
				return false;
			}
			if (y < 3 && array[x][y] == array[x][y + 1])
			{
				return false;
			}
			if (x < 3 && array[x][y] == array[x + 1][y])
			{
				return false;
			}
			if (y < 3 && array[x][y] == array[x][y + 1])
			{
				return false;
			}
			if (x < 3 && array[x][y] == array[x + 1][y])
			{
				return false;
			}
		}
	}
	return true;
}

void drawBoard(RenderWindow& window, const Font& font, const int array[4][4],int score, int highscore)
{
	float x = 0;
	float y = 0;
	float step = 85 + 10;
	float gridSize = 4 * 85 + 3 * 10;
	float X = (1000 - gridSize) / 2;
	float Y = (1000 - gridSize) / 2;

	RectangleShape rectangle({ gridSize + 20, gridSize + 20 });
	RectangleShape box;
	Text text(font, "0", 30);

	rectangle.setPosition({ X - 10, Y - 10 });
	rectangle.setFillColor(Color(255, 218, 185));

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
			else if (array[i][j] > 100)
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
	Text scoreText(font, "0", 30);
	scoreText.setString("Score: " + to_string(score));
	scoreText.setFillColor(Color::Black);
	if (current_theme == 1)
	{
		scoreText.setFillColor(Color::White);
	}
	scoreText.setPosition({ X - 10, Y - 60 });
	window.draw(scoreText);
	Text bestText(font, "0", 30);
	bestText.setString("Best: " + to_string(highscore));
	bestText.setFillColor(Color::Black);
	if (current_theme == 1)
	{
		bestText.setFillColor(Color::White);
	}
	bestText.setPosition({ X+ 250, Y - 60 });
	window.draw(bestText);
}