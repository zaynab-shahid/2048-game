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

bool Won(const int array[][4])
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

bool lost(const int array[][4])
{
	bool full = is_full(array);
	if (full == true)
	{
		return true;
	}
	return false;
}

void new_number(int array[][4])
{
	if (lost(array) == true)
	{
		return;
	}
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
bool is_full( const int array[][4])
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

	float pos = 190;
	Text boardTitle(font, "2048", 70);
	boardTitle.setPosition({ X - 10, 30 });

	RectangleShape scoreBox({ 130.f, 90.f });
	scoreBox.setPosition({ 450, 50 });
	

	RectangleShape bestScoreBox({ 130.f,90.f });
	bestScoreBox.setPosition({ 600, 50 });


	Text scoreText(font, "0", 25);
	scoreText.setString("Score: " + to_string(score));
	scoreText.setFillColor(Color::Black);
	centerText(scoreText, scoreBox);

	Text bestText(font, "0", 25);
	bestText.setString("Best: " + to_string(highscore));
	bestText.setFillColor(Color::Black);
	centerText(bestText, bestScoreBox);

	Text timeText(font, "0", 25);
	timeText.setString("Time: " + to_string(timeLeft));
	timeText.setFillColor(Color::Black);

	RectangleShape soundButton({ 150.f, 40.f });
	soundButton.setPosition({ X - 10, pos });
	Text soundText(font, "Sound: ON", 20);
	soundButton.setOutlineThickness(3.f);
	soundButton.setOutlineColor(Color::Black);
	centerText(soundText, soundButton);

	RectangleShape themeButton({ 150.f, 40.f });
	themeButton.setPosition({ X+155, pos });
	themeButton.setOutlineColor(Color::Black);
	themeButton.setOutlineThickness(3.f);
	Text themeText(font, "Theme: Standard", 20);
	themeText.setFillColor(Color::White);
	centerText(themeText, themeButton);

	RectangleShape retry({ 150.f, 40.f });
	retry.setPosition({ X+320, pos });
	retry.setOutlineThickness(3.f);
	RectangleShape menu({ 150.f, 40.f });
	menu.setPosition({ X+500, pos });
	menu.setOutlineThickness(3.f);

	Text restart(font, "Restart", 20);
	centerText(restart, retry);
	Text returnMenu(font, "Menu", 20);
	centerText(returnMenu, menu);

	if (current_theme == 0)
	{
		boardTitle.setFillColor(Color(119, 110, 101));
	    scoreBox.setFillColor(Color(255, 218, 185));
	    bestScoreBox.setFillColor(Color(255, 218, 185));
		themeButton.setFillColor(Color(143, 122, 102));
		themeText.setString("Theme: Standard");
		soundButton.setFillColor(Color(143, 122, 102));
		menu.setFillColor(Color(143, 122, 102));
	    retry.setFillColor(Color(143, 122, 102));
	}
	else if (current_theme == 1)
	{
		boardTitle.setFillColor(Color::White);
		boardTitle.setFillColor(Color::White);
		scoreBox.setFillColor(Color::White);
		scoreText.setFillColor(Color::White);
		bestText.setFillColor(Color::White);
		bestScoreBox.setFillColor(Color::White);
		timeText.setFillColor(Color::White);
		soundButton.setOutlineColor(Color::White);
		soundButton.setFillColor(Color(109, 93, 211));
		themeButton.setFillColor(Color(109, 93, 211));
		menu.setFillColor(Color({ 109,93,211 }));
	}
	else if (current_theme == 2)
	{
		
		boardTitle.setFillColor(Color(34, 139, 34));
		scoreBox.setFillColor(Color(34, 139, 34));
		bestScoreBox.setFillColor(Color(34, 139, 34));
		themeButton.setFillColor(Color(109, 93, 211));
		soundButton.setFillColor(Color(86, 117, 89));

	}
	if (sound == false)
	{
		soundText.setString("Sound: OFF");
		centerText(soundText, soundButton);

	}
	timeText.setPosition({ X - 10 , 125 });
	window.draw(timeText);
	window.draw(boardTitle);
	window.draw(scoreBox);
	window.draw(scoreText);
	window.draw(bestScoreBox);
	window.draw(bestText);
	window.draw(soundButton);
	window.draw(soundText);
	window.draw(themeButton);
	window.draw(themeText);
	window.draw(retry);
	window.draw(menu);
	window.draw(returnMenu);
	window.draw(restart);
	
	
}

void winScreenInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4])
{
	const auto* mouse = event.getIf<Event::MouseButtonPressed>();
	if (!mouse || mouse->button != Mouse::Button::Left)
		return;

	Vector2f clickPos = window.mapPixelToCoords(mouse->position);

	FloatRect retryBounds({ 165.f, 570.f }, { 220.f, 75.f });
	FloatRect menuBounds({ 415.f, 570.f }, { 220.f, 75.f });

	if (retryBounds.contains(clickPos))
	{
		score = 0;
		for (int r = 0; r < 4; r++)
			for (int c = 0; c < 4; c++)
				array[r][c] = 0;
		new_number(array);
		new_number(array);
		state = PLAYING;
	}
	else if (menuBounds.contains(clickPos))
	{
		state = MENU;
	}
}
void winScreen(RenderWindow& window, const Font& font, const int array[4][4], int score, int highscore)
{
	Text title(font, "YOU WON!", 90);
	title.setPosition({ 170.f , 280.f });
	Text description(font, "You reached 2048! Replay or go back to menu?", 20);

	//description.setPosition({ 225.f, 220.f });
	description.setPosition({ 195.f, 405.f });

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

void loseScreenInput(const Event& event, const RenderWindow& window, GameState& state, int& score, int array[4][4])
{
	const auto* mouse = event.getIf<Event::MouseButtonPressed>();
	if (!mouse || mouse->button != Mouse::Button::Left)
		return;

	Vector2f clickPos = window.mapPixelToCoords(mouse->position);

	FloatRect retryBounds({ 165.f, 570.f }, { 220.f, 75.f });
	FloatRect menuBounds({ 415.f, 570.f }, { 220.f, 75.f });

	if (retryBounds.contains(clickPos))
	{
		score = 0;
		for (int r = 0; r < 4; r++)
			for (int c = 0; c < 4; c++)
				array[r][c] = 0;

		new_number(array);
		new_number(array);
		state = PLAYING;
	}
	else if (menuBounds.contains(clickPos))
	{
		state = MENU;
	}
}

void loseScreen(RenderWindow& window, const Font& font, const int array[4][4], int score, int highscore)
{
	Text title(font, "YOU LOST!", 90);
	title.setPosition({ 162.f , 280.f });
	Text description(font, "YOU RAN OUT OF TIME/SPACE!", 20);

	description.setPosition({ 249.f, 405.f });

	RectangleShape retry({ 220.f, 75.f });
	retry.setPosition({ 165.f, 570.f });
	RectangleShape menu({ 220.f, 75.f });
	menu.setPosition({ 415.f, 570.f });

	Text restart(font, "Retry", 27);
	restart.setPosition({ 242.f, 590.f });
	Text returnMenu(font, "Menu", 27);
	returnMenu.setPosition({ 491.f, 590.f });

	Text scoreText(font, "Score: " + to_string(score), 22);
	scoreText.setPosition({ 349.f, 476.f });
	Text bestScore(font, "Best: " + to_string(highscore), 22);
	bestScore.setPosition({ 349.f, 501.f });

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