#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
Color getTileColor(int value)
{
	if (value == 0)
	{
		return Color(255, 218, 185);
	}
	else if (value == 2)
	{
		return Color(255, 224, 189);
	}
	else if (value == 4)
	{
		return Color(198, 134, 66);
	}
	else if (value == 8)
	{
		return Color(255, 200, 100);
	}
	else if (value == 16)
	{
		return Color(255, 140, 0);
	}
	else if (value == 32)
	{
		return Color(0, 128, 0);
	}
	else if (value == 64)
	{
		return Color(128, 0, 128);
	}
	else if (value == 128)
	{
		return Color(255, 255, 0);
	}
	else if (value == 256)
	{
		return Color(0, 255, 255);
	}
	else if (value == 512)
	{
		return Color(128, 128, 128);
	}
	else if (value == 1024)
	{
		return Color(165, 42, 42);
	}
	else if (value == 2048)
	{
		return Color(255, 215, 0);
	}
	else
	{
		return Color::Black;
	}
}
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
			array[x][y] = 2;
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
		}

	}
int main()
{
	srand(time(0));
	int array[4][4] = {0};
	
	
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
	text.setFillColor(Color::Black);
	text.setPosition({ x+25, y+25 });

	rectangle.setPosition({ X-10, Y-10 });
	rectangle.setFillColor(Color(255, 218, 185));

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
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
				else if (array[i][j])
				{
					text.setCharacterSize(24);
				}
				else
				{
					text.setCharacterSize(26);
				}
				if(array[i][j] == 0)
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


