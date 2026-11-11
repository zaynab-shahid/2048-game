#include <SFML/Graphics.hpp>
#include <iostream>


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
	int array[4][4] = {
		{2,2, 4, 4},
		{2, 0, 0, 2},
		{8, 4, 4, 2},
		{2, 2, 4, 0}
	};

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