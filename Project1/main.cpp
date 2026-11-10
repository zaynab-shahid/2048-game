#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void right(int array[][4])
{
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (array[r][c + 1] == 0)
			{
				array[r][c + 1] = array[r][c];
				array[r][c] = 0;
			}
			if (array[r][c] == array[r][c + 1])
			{
				array[r][c] = 0;
				array[r][c + 1] = array[r][c + 1] * 2;
			}
		}
	}
}

int main()
{
	int array[4][4] = {
		{2, 0, 2, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	right(array);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << '\n';
	}
	RenderWindow window(VideoMode({ 800, 600 }), "Random Title");

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
		}
		window.clear(Color(187, 173, 160));
		window.display();
	}
	return 0;

}

