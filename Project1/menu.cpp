#include "menu.h"
#include "theme.h"

void menuInput(const Event& event, GameState& state)
{
    const Event::MouseButtonPressed* mousePressed = event.getIf<Event::MouseButtonPressed>();
    if (mousePressed != nullptr && mousePressed->button == Mouse::Button::Left)
    {
        FloatRect themeBounds({ 340.f, 450.f }, { 320.f, 80.f });
        Vector2f clickPos(mousePressed->position.x, mousePressed->position.y);

        if (themeBounds.contains(clickPos))
        {
            current_theme = current_theme + 1;
            if (current_theme > 2)
            {
                current_theme = 0;
            }
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
    title.setPosition({ 385.f, 220.f });

    RectangleShape themeButton({ 320.f, 80.f });
    themeButton.setPosition({ 340.f, 450.f });

    Text themeText(font, "Theme: Standard", 34);
    themeText.setFillColor(Color::White);
    themeText.setPosition({ 362.f, 470.f });

    Text hint(font, "Press Enter to play", 24);
    hint.setPosition({ 382.f, 570.f });

    if (current_theme == 0)
    {
        title.setFillColor(Color(119, 110, 101));
        themeButton.setFillColor(Color(143, 122, 102));
        themeText.setString("Theme: Standard");
        hint.setFillColor(Color(119, 110, 101));
    }
    else if (current_theme == 1)
    {
        title.setFillColor(Color::White);
        themeButton.setFillColor(Color(109, 93, 211));
        themeText.setString("Theme: Neon");
        hint.setFillColor(Color(180, 185, 215));
    }
    else
    {
        title.setFillColor(Color(119, 110, 101));
        themeButton.setFillColor(Color(86, 117, 89));
        themeText.setString("Theme: Forest");
        hint.setFillColor(Color(119, 110, 101));
    }

    window.draw(title);
    window.draw(themeButton);
    window.draw(themeText);
    window.draw(hint);
}