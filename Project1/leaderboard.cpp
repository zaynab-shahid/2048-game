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
void drawLeaderboard(RenderWindow& window,const Font& font,const int board[5])
{
	Text Leaderboard(font, "Leaderboard", 70);
	Leaderboard.setPosition({ 220.f , 100.f });
	Leaderboard.setFillColor(Color::Black);
	if (current_theme == 1)
	{
		Leaderboard.setFillColor(Color::White);
	}
	window.draw(Leaderboard);
	for (int i = 0;i <= 4; i++)
	{
		Text row(font, "0", 40);
		
		row.setString(to_string(i+1)+". "+to_string(board[i]));
		row.setFillColor(Color::Black);
		if (current_theme == 1)
		{
			row.setFillColor(Color::White);
		}
		row.setPosition({ 300.f,250.f + i * 70.f });
		window.draw(row);
	}
	Text backText(font, "Press Esc to go back", 22);
	backText.setPosition({290.f,700.f});
	backText.setFillColor(Color::Black);
	if (current_theme == 1)
	{
		backText.setFillColor(Color::White);
	}
	window.draw(backText);
}
void leaderboardInput(const Event& event, const RenderWindow& window, GameState& state)
{
	const Event::KeyPressed* keyPressed = event.getIf<Event::KeyPressed>();
	if (keyPressed != nullptr && keyPressed->code == Keyboard::Key::Escape)
	{
		state = MENU;
	}
}
