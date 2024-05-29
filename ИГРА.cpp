
#include <SFML/Graphics.hpp>
#include<string>
#include <iostream>

bool restart = false;
//#include"Header.h"
using namespace sf;

void menu()
{
	RenderWindow window(VideoMode(800, 600), "Заставка игры");

	Font font;
	font.loadFromFile("srift.ttf");

	Text title;
	title.setFont(font);
	title.setString("FROGGER");
	title.setCharacterSize(40);
	title.setFillColor(Color::White);
	title.setPosition(280, 100);
	int a;
	Text rules;
	rules.setFont(font);
	//rules.setString("Rules of the game:\n jump over pop its not to touch spinners\n collect pies.\n By collecting "+ std::to_string(intpirog)+ " pies you win");
	rules.setCharacterSize(24);
	rules.setFillColor(Color::White);
	rules.setPosition(100, 200);

	RectangleShape button(Vector2f(250, 50));
	button.setFillColor(Color::Magenta);
	button.setPosition(275, 400);

	Text buttonText;
	buttonText.setFont(font);
	buttonText.setString("start the game!!!");
	buttonText.setCharacterSize(24);
	buttonText.setFillColor(Color::White);
	buttonText.setPosition(295, 410);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					// Проверяем, было ли нажатие на кнопку "Начать игру"
					if (button.getGlobalBounds().contains(window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						std::cout << "Начало игры!\n";
						window.close();
						//game_run();
					}
				}
			}
		}

		window.clear(Color{ 55, 55, 55 });
		window.draw(title);
		window.draw(rules);
		window.draw(button);
		window.draw(buttonText);
		window.display();
	}
}

int main()
{
	menu();
	while (restart)
	{
		restart = false;
		menu();
		
	}

    return 0;
}