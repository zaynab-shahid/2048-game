#include"color.h"

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