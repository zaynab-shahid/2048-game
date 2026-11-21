#include "menu.h"
#include "theme.h"
using namespace sf;
int current_mode = 0;
bool sound = true;

void centerText(Text& text, RectangleShape& button)
{
    FloatRect textRect = text.getLocalBounds();
    FloatRect buttonSize = button.getGlobalBounds();

	text.setOrigin({textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f});
	text.setPosition(button.getPosition() + sf::Vector2f(button.getSize().x / 2.0f, button.getSize().y / 2.0f ));
}
void menuInput(const Event& event, GameState& state)
{
    const Event::MouseButtonPressed* mousePressed = event.getIf<Event::MouseButtonPressed>();
    if (mousePressed != nullptr && mousePressed->button == Mouse::Button::Left)
    {
        FloatRect themeBounds({ 340.f, 250.f }, { 320.f, 80.f });
        Vector2f clickPos(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));

		FloatRect difficultyBounds({ 340.f, 350.f }, { 320.f, 80.f });
		FloatRect soundBounds({ 340.f, 450.f }, { 320.f, 80.f });
		FloatRect playBounds({ 340.f, 550.f }, { 320.f, 80.f });
		

        if (themeBounds.contains(clickPos))
        {
            current_theme = current_theme + 1;
            if (current_theme > 2)
            {
                current_theme = 0;
            }
        }
		if (difficultyBounds.contains(clickPos))
		{
            current_mode = (current_mode + 1);
			if (current_mode > 3)
			{
				current_mode = 0;
			}
		}
        if(soundBounds.contains(clickPos))
        {
            if(sound)
			{
				sound = false;
			}
            else if (sound == false)
            {
                sound = true;
            }
			
        }
        if(playBounds.contains(clickPos))
        {
            state = PLAYING;
        }
    }

    const Event::KeyPressed* keyPressed = event.getIf<Event::KeyPressed>();
    if (keyPressed != nullptr && keyPressed->code == Keyboard::Key::Enter)
    {
        state = PLAYING;
    }
}

void drawMenu(RenderWindow& window, const Font& font)
{
    Text title(font, "2048", 90);
    title.setPosition({ 385.f, 100.f });

	Text description(font, "C++/SFML-Fundamental Programming Project", 24);
	description.setPosition({ 270.f, 200.f });
    description.setFillColor(Color::Black);
	
    RectangleShape themeButton({ 320.f, 80.f });
    themeButton.setPosition({ 340.f, 250.f });
    
    RectangleShape themeButtonBorder({ 320.f, 80.f });
	themeButtonBorder.setPosition({ 340.f, 250.f });
	themeButtonBorder.setFillColor(Color::Transparent);
	themeButtonBorder.setOutlineColor(Color::White);
	themeButtonBorder.setOutlineThickness(3.f);

	RectangleShape difficulty({ 320.f, 80.f });
	difficulty.setPosition({ 340.f, 350.f });
	difficulty.setOutlineColor(Color::White);
	difficulty.setOutlineThickness(3.f);

    Text difficultyText(font, "Difficulty: Easy", 34);
    difficultyText.setPosition({ 320.f, 370.f });
    difficultyText.setFillColor(Color::White);
  
    RectangleShape soundButton({ 320.f, 80.f });
	soundButton.setPosition({ 340.f, 450.f });
    Text soundText(font, "Sound: ON", 34);
    soundButton.setOutlineThickness(3.f);
    centerText(soundText, soundButton);

	RectangleShape playButton({ 320.f, 80.f });
	playButton.setPosition({ 340.f, 550.f });
    playButton.setOutlineThickness(3.f);

    Text themeText(font, "Theme: Standard", 34);
    themeText.setFillColor(Color::White);
    themeText.setPosition({ 362.f, 270.f });
   
	Text playText(font, "Play", 34);
	playText.setPosition({ 340.f, 570.f });
    playText.setFillColor(Color::White);
    centerText(playText, playButton);

    Text hint(font, "Press Enter to play", 20);
    hint.setPosition({ 420.f, 650.f });



    if (current_mode == 0)
    {
		
		difficultyText.setString("Difficulty: Easy");
        centerText(difficultyText, difficulty);
		
    }
    else if (current_mode == 1)
    {
		
		
		difficultyText.setString("Difficulty: Medium");
        centerText(difficultyText, difficulty);
		
    }
    else if (current_mode == 2)
    {


        difficultyText.setString("Difficulty: Hard");
        centerText(difficultyText, difficulty);

    }
	else if (current_mode == 3)
	{
		difficultyText.setString("Difficulty: Extra Hard");
        centerText(difficultyText, difficulty);
	}

    if (current_theme == 0)
    {
        title.setFillColor(Color(119, 110, 101));
        themeButton.setFillColor(Color(143, 122, 102));
        themeText.setString("Theme: Standard");
		centerText(themeText, themeButton);
        playButton.setFillColor(Color(143, 122, 102));
        hint.setFillColor(Color(119, 110, 101));
        playButton.setOutlineColor(Color::Black);
		themeButtonBorder.setOutlineColor(Color::Black);
        difficulty.setOutlineColor(Color::Black);
		difficulty.setFillColor(Color(143, 122, 102));
        soundButton.setOutlineColor(Color::Black);
        soundButton.setFillColor(Color(143, 122, 102));
		
		
    }
    else if (current_theme == 1)
    {
        title.setFillColor(Color::White);
        themeButton.setFillColor(Color(109, 93, 211));
        themeText.setString("Theme: Neon");
		centerText(themeText, themeButton);
        themeButtonBorder.setOutlineColor(Color::White);
		description.setFillColor(Color::White);
        playButton.setFillColor(Color(109, 93, 211));
        playButton.setOutlineColor(Color::White);
        hint.setFillColor(Color(180, 185, 215));
        difficulty.setOutlineColor(Color::White);
        difficulty.setFillColor(Color(109, 93, 211));
        soundButton.setOutlineColor(Color::White);
		soundButton.setFillColor(Color(109, 93, 211));
		
		
		
    }
    else
    {
        title.setFillColor(Color(34, 139, 34));
        themeButton.setFillColor(Color(86, 117, 89));
        themeText.setString("Theme: Forest");
		centerText(themeText, themeButton);
        playButton.setFillColor(Color(86, 117, 89));
        playButton.setOutlineColor(Color::Black);
        hint.setFillColor(Color(86, 117, 89));
		themeButtonBorder.setOutlineColor(Color::Black);
        difficulty.setOutlineColor(Color::Black);
		difficulty.setFillColor(Color(86, 117, 89));
        soundButton.setOutlineColor(Color::Black);
		soundButton.setFillColor(Color(86, 117, 89));
		
		
    }
    if (sound==false)
    {
        soundText.setString("Sound: OFF");
		centerText(soundText , soundButton);
        
    }

    window.draw(title);
    window.draw(description);
    window.draw(themeButton);
    window.draw(themeButtonBorder);
    window.draw(themeText);
	window.draw(playButton);
	window.draw(playText);
    window.draw(hint);
	window.draw(difficulty);
	window.draw(difficultyText);
    window.draw(soundButton);
    window.draw(soundText);
}