#include <SFML/Audio.hpp>
#include"movement.h"
#include "board.h"
#include"sound.h"
void right(int array[][4], int &score)
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
				score += array[i][j];
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
void left(int array[][4], int &score)
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
				score += array[i][j];
				
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

void top(int array[][4], int &score)
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
				score += array[j][i];
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

void bottom(int array[][4], int &score)
{
	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		while (count < 2)
		{
			for (int j = 2; j >= 0; j--)
			{
				if (array[j + 1][i] == 0)
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
				score += array[j + 1][i];
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

void keys(const Event::KeyPressed& keyPressed, int array[][4], int &score,gameSound &Sound)
	{
		if (keyPressed.code == Keyboard::Key::Left)
		{
			int before[4][4];
			for(int i=0;i<4;i++)
				for (int j = 0;j < 4;j++)
				{
					before[i][j] = array[i][j];
				}
			int scoreBefore = score;
			left(array, score);
			bool move = false;
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					if (before[i][j] != array[i][j])
						move = true;
				}
			if(move)
			{
				if (sound)
				{
					if (score > scoreBefore) Sound.playMergeSound();
					else                     Sound.playMoveSound();
				}
			}

			
			
			new_number(array);
		}
		else if (keyPressed.code == Keyboard::Key::Right)
		{
			int before[4][4];
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					before[i][j] = array[i][j];
				}
			int scoreBefore = score;
			right(array, score);
			bool move = false;
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					if (before[i][j] != array[i][j])
						move = true;
				}
			if (move)
			{
				if (sound)
				{
					if (score > scoreBefore) Sound.playMergeSound();
					else                     Sound.playMoveSound();
				}
			}

			

			new_number(array);
		}
		else if (keyPressed.code == Keyboard::Key::Up)
		{
			int before[4][4];
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					before[i][j] = array[i][j];
				}
			int scoreBefore = score;
			top(array, score);
			bool move = false;
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					if (before[i][j] != array[i][j])
						move = true;
				}
			if (move)
			{
				if (sound)
				{
					if (score > scoreBefore) Sound.playMergeSound();
					else                     Sound.playMoveSound();
				}
			}
			

			

			new_number(array);
		}
		else if (keyPressed.code == Keyboard::Key::Down)
		{
			int before[4][4];
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					before[i][j] = array[i][j];
				}
			int scoreBefore = score;
			bottom(array, score);
			bool move = false;
			for (int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					if (before[i][j] != array[i][j])
						move = true;
				}
			if (move)
			{
				if (sound)
				{
					if (score > scoreBefore) Sound.playMergeSound();
					else                     Sound.playMoveSound();
				}
			}
			
			new_number(array);
		}
	}