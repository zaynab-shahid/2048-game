#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void left(int array[][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[j][i + 1] == 0)
			{
				array[j][i + 1] = array[j][i];
				array[j][i] = 0;
			}
		}
	}
}

int main()
{
	int array[4][4] = {
		{2, 0, 0, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

<<<<<<< Updated upstream
    // test pushhh

    return 0;
}
=======
	left(array);

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
>>>>>>> Stashed changes
