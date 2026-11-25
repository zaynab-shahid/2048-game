#include <SFML/Graphics.hpp>
#include"howtoplay.h"
#include"menu.h"
#include"board.h"
#include"theme.h"
using namespace sf;

void drawHowToPlay(RenderWindow& window, const Font& font)
{
    
    
    Text HowToPlayText(font, "How to Play", 60);
    HowToPlayText.setPosition({ 250.f, 100.f });
    HowToPlayText.setFillColor(Color::Black);
    Text Instructions(font,

        ".GOAL\n"
        "-Combine tiles with the same number to reach the 2048 tile.\n"

        ".CONTROLS\n"
        "-Use the arrow keys(or W A S D) to slide all tiles in one direction.\n"

        ".RULES\n"
        "- When two tiles with the same number touch, they merge into one tile with \ndouble the value.\n"
        "- After every move, a new tile(2 or 4) appears in an empty cell.\n"
        "- Each merge adds the new tile's value to your score.\n"
        "- The game ends when the board is full and no merges are possible.\n"
        ".MODES\n"
        "- Difficulty changes the grid / time limit. (Edit this to match your Easy / Medium \n/ Hard.)\n"
        "- Your best score is saved and shown in the Best box.\n"

        " (Press Esc or click Back to return to the menu).\n", 20);

	Instructions.setPosition({ 50.f, 200.f });
    Instructions.setFillColor(Color::Black);
    if (current_theme == 1)
    {
        Instructions.setFillColor(Color::White);
        HowToPlayText.setFillColor(Color::White);
    }
    
	RectangleShape backButton({ 160.f, 60.f });
	backButton.setFillColor(Color(109, 93, 211));
	backButton.setOutlineColor(Color::White);
	backButton.setPosition({ 320.f, 600.f });

	Text backText(font, "Back", 26);
	centerText(backText, backButton);
   
	window.draw(HowToPlayText);
	window.draw(Instructions);
	window.draw(backButton);
	window.draw(backText);
	
}