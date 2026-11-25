#include <SFML/Graphics.hpp>
#include"board.h"
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <string>
#include "color.h"
#include"theme.h"
#include "menu.h"
using namespace sf;
using namespace std;

bool Won(const int array[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] >= 2048)
			{
				return true;
			}
		}
	}
	return false;
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

void drawBoard(RenderWindow& window, const Font& font, const int array[4][4],int score, int highscore, int timeLeft)
{
	float x = 0;
	float y = 0;

	float tileSize = 155;
	float step = tileSize + 10;
	float gridSize = 4 * tileSize + 3 * 10;
	float X = (800 - gridSize) / 2;
	float Y = 270 ;


	RectangleShape rectangle({ gridSize + 20, gridSize + 20 }); // grid
	RectangleShape box; // each tile
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
			box.setSize({ tileSize, tileSize });
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
			if (array[i][j] != 0)
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
	Text timeText(font, "0", 30);
	timeText.setString("Time: " + to_string(timeLeft));
	timeText.setFillColor(Color::Black);
	if (current_theme == 1)
	{
		timeText.setFillColor(Color::White);
	}
	timeText.setPosition({ X - 10, Y + 400 });
	window.draw(timeText);
}

void winScreenInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4])
{
	const auto* mouse = event.getIf<Event::MouseButtonPressed>();
	if (!mouse || mouse->button != Mouse::Button::Left)
		return;

	Vector2f clickPos = window.mapPixelToCoords(mouse->position);

	FloatRect retryBounds({ 200.f, 340.f }, { 220.f, 75.f });
	FloatRect menuBounds({ 450.f, 340.f }, { 220.f, 75.f });

if (retryBounds.contains(clickPos))
{
	score = 0;
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			array[r][c] = 0;

	state = GameState::PLAYING;
}
else if (menuBounds.contains(clickPos))
{
	state = GameState::MENU;
}
}
void winScreen(RenderWindow& window, const Font& font, const int array[4][4], int score, int highscore)
{
	Text title(font, "YOU WON!", 90);
	title.setPosition({ 170.f , 280.f });
	Text description(font, "You reached 2048! Retry or go back to menu?", 20);
<<<<<<< HEAD
	description.setPosition({ 225.f, 220.f });
=======
	description.setPosition({ 195.f, 405.f });
>>>>>>> 3a5a4f3f5780e011e8c69923df95284ab6940c9f

	RectangleShape retry({ 220.f, 75.f });
	retry.setPosition({ 165.f, 570.f });
	RectangleShape menu({ 220.f, 75.f });
	menu.setPosition({ 415.f, 570.f });

	Text restart(font, "Restart", 27);
	restart.setPosition({ 231.f, 590.f });
	Text returnMenu(font, "Menu", 27);
	returnMenu.setPosition({ 491.f, 590.f });

	Text scoreText(font, "Score: " + to_string(score), 22);
	scoreText.setPosition({ 335.f, 476.f });
	Text bestScore(font, "Best: " + to_string(highscore), 22);
	bestScore.setPosition({ 335.f, 501.f });

	RectangleShape scoreBox({ 230.f, 64.f });
	scoreBox.setPosition({ 285.f, 470.f });
	scoreBox.setOutlineThickness(2.f);

	if (current_theme == 0)
	{
		title.setFillColor(Color(119, 110, 101));
		description.setFillColor(Color(145, 134, 123));
		retry.setFillColor(Color(143, 122, 102));
		menu.setFillColor(Color(143, 122, 102));
		restart.setFillColor(Color(249, 246, 242));
		returnMenu.setFillColor(Color(249, 246, 242));
		scoreBox.setFillColor(Color(235, 226, 213));
		scoreBox.setOutlineColor(Color(187, 173, 160));
		scoreText.setFillColor(Color(119, 110, 101));
		bestScore.setFillColor(Color(68, 98, 76));
		window.clear(Color(250, 248, 239));
	}
	else if (current_theme == 1)
	{
		title.setFillColor(Color(22, 24, 42));
		description.setFillColor(Color(175, 185, 225));
		retry.setFillColor(Color(38, 42, 74));
		menu.setFillColor(Color(0, 210, 211));
		restart.setFillColor(Color(0, 255, 200));
		returnMenu.setFillColor(Color(18, 20, 38));
		scoreBox.setFillColor(Color(28, 32, 58));
		scoreBox.setOutlineColor(Color(168, 85, 247));
		scoreText.setFillColor(Color(0, 255, 200));
		bestScore.setFillColor(Color(175, 185, 225));
		window.clear(Color(245, 248, 255));
	}
	else if (current_theme == 2)
	{
		title.setFillColor(Color(32, 56, 39));
		description.setFillColor(Color(68, 98, 76));
		retry.setFillColor(Color(76, 122, 86));
		menu.setFillColor(Color(62, 110, 74));
		restart.setFillColor(Color(245, 247, 240));
		returnMenu.setFillColor(Color(245, 247, 240));
		scoreBox.setFillColor(Color(208, 221, 198));
		scoreBox.setOutlineColor(Color(114, 148, 118));
		scoreText.setFillColor(Color(32, 56, 39));
		bestScore.setFillColor(Color(68, 98, 76));
		window.clear(Color(235, 240, 228));
	}


	window.draw(menu);
	window.draw(retry);
	window.draw(description);
	window.draw(title);
	window.draw(restart);
	window.draw(returnMenu);
	window.draw(scoreBox);
	window.draw(scoreText);
	window.draw(bestScore);
}
void howToPlayInput(const Event& event, const RenderWindow& window, GameState& state)
{
	if (state != HOWTOPLAY)
		return;
	const Event::MouseButtonPressed* mousePressed = event.getIf<Event::MouseButtonPressed>();
	Vector2f clickPos(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));
	if (!mousePressed || mousePressed->button != Mouse::Button::Left)
	{
		
		FloatRect howToPlayBounds({ 100.f, 750.f }, { 160.f, 60.f });	
		if (howToPlayBounds.contains(clickPos))
		{
			state = HOWTOPLAY;
		}
		const Event::KeyPressed* keyPressed = event.getIf<Event::KeyPressed>();
	    if (state == HOWTOPLAY )
	    {
		  if (keyPressed != nullptr && keyPressed->code == Keyboard::Key::Escape)
		   {
			state = MENU;
		   }
	    }
	
	}
	
	
	

}