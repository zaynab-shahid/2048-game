#include "color.h"
#include "theme.h"

sf::Color getTileColor(int value)
{
	if (value == 0)
	{
		return themes[current_theme][0];
	}
	else if (value == 2)
	{
		return themes[current_theme][1];
	}
	else if (value == 4)
	{
		return themes[current_theme][2];
	}
	else if (value == 8)
	{
		return themes[current_theme][3];
	}
	else if (value == 16)
	{
		return themes[current_theme][4];
	}
	else if (value == 32)
	{
		return themes[current_theme][5];
	}
	else if (value == 64)
	{
		return themes[current_theme][6];
	}
	else if (value == 128)
	{
		return themes[current_theme][7];
	}
	else if (value == 256)
	{
		return themes[current_theme][8];
	}
	else if (value == 512)
	{
		return themes[current_theme][9];
	}
	else if (value == 1024)
	{
		return themes[current_theme][10];
	}
	else if (value == 2048)
	{
		return themes[current_theme][11];
	}
	else
	{
		return sf::Color::Black;
	}
}
