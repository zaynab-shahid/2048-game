#pragma once
#include <SFML/Graphics.hpp>

inline int current_theme = 0;

static sf::Color themes[][12]{
	{
	 sf::Color(205, 193, 180), sf::Color(238, 228, 218), sf::Color(237, 224, 200),
	 sf::Color(242, 177, 121), sf::Color(245, 149, 99), sf::Color(246, 124, 95),
	 sf::Color(246, 94, 59), sf::Color(237, 207, 114), sf::Color(237, 204, 97),
	 sf::Color(237, 200, 80), sf::Color(237, 197, 63), sf::Color(237, 194, 46)
	},
	{
	 sf::Color(44, 46, 74), sf::Color(68, 96, 156), sf::Color(78, 114, 186),
	 sf::Color(0, 168, 232), sf::Color(0, 212, 212), sf::Color(16, 185, 129),
	 sf::Color(52, 211, 153), sf::Color(168, 85, 247), sf::Color(217, 70, 239),
	 sf::Color(236, 72, 153), sf::Color(251, 191, 36), sf::Color(250, 204, 21)
	},
	{
	 sf::Color(143, 163, 140), sf::Color(226, 236, 211), sf::Color(207, 223, 184),
	 sf::Color(169, 214, 129), sf::Color(126, 194, 98), sf::Color(72, 173, 97),
	 sf::Color(46, 145, 82), sf::Color(134, 179, 107), sf::Color(109, 158, 86),
	 sf::Color(85, 138, 69), sf::Color(186, 176, 82), sf::Color(212, 185, 68)
	},
};
