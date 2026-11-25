#include"leaderboard.h"
#include<fstream>
#include<string>
#include"menu.h"
#include"theme.h"
using namespace std;
void loadLeaderboard(int board[5])
{
	for (int i = 0;i <= 4;i++)
	{
		board[i] = 0;
	}
		ifstream infile("leaderboard.txt");
	
	for(int i=0;i<=4;i++)
	{
		infile >> board[i];
	}
}
void addScore(int board[5], int score)
{
	int temp;
	if (score <= board[4])
	{
		return ;
	}
	board[4] = score;
	for (int i = 4;i >= 1;i--)
	{
		if (board[i] > board[i - 1])
		{
			temp = board[i];
			board[i] = board[i - 1];
			board[i - 1] = temp;
		}
	}
	ofstream outfile("leaderboard.txt");
	for (int i = 0;i <= 4;i++)
	{
		outfile << board[i] << endl;
	}
}
void drawLeaderboard(RenderWindow& window, const Font& font, const int board[5])
{
	Text Leaderboard(font, "Leaderboard", 60);
	Leaderboard.setPosition({ 210.f , 100.f });
	for (int i = 0;i <= 4; i++)
	{
		Text row(font, "0", 40);

		row.setString(to_string(i + 1) + ". " + to_string(board[i]));
		row.setFillColor(Color::Black);
		if (current_theme == 1)
		{
			row.setFillColor(Color::White);
		}
		row.setPosition({ 300.f,250.f + i * 70.f });
		window.draw(row);
	}
	RectangleShape back({ 260.f,60.f });
	back.setPosition({ 260.f, 650.f });

	Text backText(font, "Press Esc to go back", 22);
	centerText(backText, back);
	backText.setFillColor(Color::White);
	back.setOutlineColor(Color::Black);
	if (current_theme == 0)
	{
		Leaderboard.setFillColor(Color(143, 122, 102));
		back.setFillColor(Color(143, 122, 102));
	}
	else if (current_theme == 1)
	{
		
		Leaderboard.setFillColor(Color::White);
		back.setFillColor(Color(109, 93, 211));
		back.setOutlineColor(Color::White);
	}
	else
	{
		Leaderboard.setFillColor(Color(86, 117, 89));
		back.setFillColor(Color(86, 117, 89));
	}
	back.setOutlineThickness(3.f);
	window.draw(back);
	window.draw(backText);
	window.draw(Leaderboard);
}
void leaderboardInput(const Event& event, const RenderWindow& window, GameState& state)
{
	const Event::KeyPressed* keyPressed = event.getIf<Event::KeyPressed>();
	if (keyPressed != nullptr && keyPressed->code == Keyboard::Key::Escape)
	{
		state = MENU;
	}
}
