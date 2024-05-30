
#include <SFML/Graphics.hpp>
#include<string>
#include <iostream>

bool restart = false;
//#include"Header.h"
using namespace sf;
int intpirog = 10;


void game_run()
{
	setlocale(LC_ALL, "Russian");

	RenderWindow window(VideoMode(800, 600), "GAME");

	Texture herotexture;
	herotexture.loadFromFile("imag/hiro.png");
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.scale(0.15f, 0.15f);
	herosprite.setPosition(50, 450); //выводим спрайт в позицию x y 

	Image map_image;//объект изображения для карты
	map_image.loadFromFile("imag/pole.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом
	s_map.scale(0.6f, 0.6f);
	s_map.setPosition(0, 0);

	Image popt_image;
	popt_image.loadFromFile("imag/popt.png");
	Texture popt;
	popt.loadFromImage(popt_image);
	Sprite s_popt;
	s_popt.setTexture(popt);
	s_popt.scale(0.03f, 0.03f);
	s_popt.setPosition(800, 520);

	Sprite s_popt1;
	s_popt1 = s_popt;
	s_popt1.setPosition(-150, 520);

	Image spin_image;
	spin_image.loadFromFile("imag/spin.png");
	Texture spin;
	spin.loadFromImage(spin_image);
	Sprite s_spin;
	s_spin.setTexture(spin);
	s_spin.scale(0.06f, 0.06f);
	s_spin.setPosition(400, 400);


	Image pirog_image;
	pirog_image.loadFromFile("imag/pirog.png");
	Texture pirog;
	pirog.loadFromImage(pirog_image);
	Sprite s_pirog;
	s_pirog.setTexture(pirog);
	s_pirog.scale(0.05f, 0.05f);
	s_pirog.setPosition(2400, 520);

	Image bus_image;
	bus_image.loadFromFile("imag/bus.png");
	Texture bus;
	bus.loadFromImage(bus_image);
	Sprite s_bus;
	s_bus.setTexture(bus);
	s_bus.scale(0.03f, 0.03f);
	s_bus.setPosition(650, 280);

	Image end_image;
	end_image.loadFromFile("imag/end.jpg");
	Texture end;
	end.loadFromImage(end_image);
	Sprite s_end;
	s_end.setTexture(end);
	s_end.scale(0.7f, 0.7f);
	s_end.setPosition(250, 130);
	float s_poptSpeed = 0.3f;
	float s_spinSpeed = 0.35f;
	float s_busSpeed = 0.05f;
	bool isJumping = false;
	float jumpHeight = 200.0f;
	bool isGameOver = false;
	bool run = true;
	int count = 0;

	bool isGameEnd = false;

	bool timerStarted = false;
	Clock clock;
	Text timerText;
	Font font;
	font.loadFromFile("srift.ttf");
	timerText.setFont(font);
	int seconds = 0;

	Text count_pirog;
	count_pirog.setFont(font);
	bool Game = false;
	int put = 0;

	Text buttonText;
	buttonText.setFont(font);
	buttonText.setString("press the button to restart");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(Color::White);
	buttonText.setPosition(10, 10);
	RectangleShape button(Vector2f(50, 50));
	button.setPosition(window.getSize().x - 60, window.getSize().y - 60);
	button.setFillColor(Color::White);

	Text win;
	win.setFont(font);
	win.setString("YOU WIN!!!");
	win.setCharacterSize(50);
	win.setFillColor(Color::White);
	win.setPosition(300, 150);

	int speed = 0;
	while (window.isOpen())
	{
		count++;
		if (count >= 1500)
		{
			count = 0;
			s_poptSpeed += 0.01f;
			s_spinSpeed += 0.01f;
			speed += 0.01f;
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Space)) && !isJumping && !isGameOver)
			{
				isJumping = true;
			}
		}
		if (isJumping)
		{
			herosprite.move(0, -0.5f- speed);
			jumpHeight -= 0.5f- speed;
			if (jumpHeight <= 0)
			{
				isJumping = false;
				jumpHeight = 0.0f;
			}
		}
		else if (jumpHeight < 180)
		{
			herosprite.move(0, 0.5f+ speed);
			jumpHeight += 0.5f+ speed;
		}

		s_popt.move(-s_poptSpeed, 0);
		if (s_popt.getPosition().x < -50)
		{
			s_popt.setPosition(800, 520);
		}

		s_popt1.move(-s_poptSpeed, 0);
		if (s_popt1.getPosition().x < -1700)
		{
			s_popt1.setPosition(800, 520);
		}
		s_pirog.move(-s_poptSpeed, 0);
		if (s_pirog.getPosition().x < -2400)
		{
			s_pirog.setPosition(800, 520);
		}

		float herospriteRight = herosprite.getPosition().x + 45.0f;
		float s_pirogRight = s_pirog.getPosition().x + 20.0f;

		if (herospriteRight > s_pirog.getPosition().x
			&& herosprite.getPosition().x < s_pirogRight
			&& herosprite.getPosition().y < s_pirog.getPosition().y + s_pirog.getGlobalBounds().height
			&& herosprite.getPosition().y + herosprite.getGlobalBounds().height > s_pirog.getPosition().y)
		{
			Game = true;
		}
		else if (Game)
		{
			Game = false;
			s_pirog.setPosition(2440, 550);
			put++;
		}

		herospriteRight = herosprite.getPosition().x + 40.0f;
		float s_poptRight = s_popt.getPosition().x + 15.0f;

		if (herospriteRight > s_popt.getPosition().x
			&& herosprite.getPosition().x < s_poptRight
			&& herosprite.getPosition().y < s_popt.getPosition().y + s_popt.getGlobalBounds().height
			&& herosprite.getPosition().y + herosprite.getGlobalBounds().height > s_popt.getPosition().y
			&& !isJumping)
		{
			isGameOver = true;
		}


		s_spin.move(-s_spinSpeed - speed, 0);
		if (s_spin.getPosition().x < -900)
		{
			s_spin.setPosition(900, 300 + 50 * (pow((-1), rand() % 3)));
		}
		if ((s_spin.getPosition().x > s_popt.getPosition().x && s_spin.getPosition().x - 100 <  s_popt.getPosition().x))
		{
			s_spin.move(-1 - speed, 0);
		}
		if ((s_spin.getPosition().x < s_popt.getPosition().x && s_spin.getPosition().x + 100 >  s_popt.getPosition().x))
		{
			s_spin.move(-1 - speed, 0);
		}
		if ((s_spin.getPosition().x > s_popt1.getPosition().x && s_spin.getPosition().x - 100 < s_popt1.getPosition().x))
		{
			s_spin.move(-1 - speed, 0);
		}
		if ((s_spin.getPosition().x < s_popt1.getPosition().x && s_spin.getPosition().x + 100 > s_popt1.getPosition().x))
		{
			s_spin.move(-1 - speed, 0);
		}

		herospriteRight = herosprite.getPosition().x + 40.0f;
		float s_spinRight = s_spin.getPosition().x + 15.0f;

		if (herospriteRight > s_spin.getPosition().x
			&& herosprite.getPosition().x < s_spinRight
			&& herosprite.getPosition().y < s_spin.getPosition().y + s_spin.getGlobalBounds().height
			&& herosprite.getPosition().y + herosprite.getGlobalBounds().height + 10 > s_spin.getPosition().y)
		{
			isGameOver = true;
		}

		if (!timerStarted)
		{
			timerStarted = true;
			clock.restart(); // Начать отсчет времени при старте игры
		}

		// Обновление времени после запуска игры
		seconds = static_cast<int>(clock.getElapsedTime().asSeconds());

		// Отображение времени на экране
		Text timerText;
		timerText.setFont(font);
		timerText.setCharacterSize(40);
		timerText.setFillColor(Color::White);
		timerText.setPosition(10, 10);
		timerText.setString("time: " + std::to_string(seconds));

		count_pirog.setFont(font);
		count_pirog.setCharacterSize(40);
		count_pirog.setFillColor(Color::White);
		count_pirog.setPosition(550, 10);
		count_pirog.setString("points: " + std::to_string(put));

		window.clear();
		window.draw(s_map);
		if (run && put < intpirog) {

			window.draw(s_popt1);
			if (s_popt.getPosition().x != s_pirog.getPosition().x)
			{
				window.draw(s_popt);
			}

			window.draw(s_pirog);
			window.draw(s_spin);
			if ((s_pirog.getPosition().x > s_popt.getPosition().x && s_pirog.getPosition().x - 50 < s_popt.getPosition().x))
			{
				s_pirog.move(-3-speed, 0);
			}
			if ((s_pirog.getPosition().x < s_popt.getPosition().x && s_pirog.getPosition().x + 50 >  s_popt.getPosition().x))
			{
				s_pirog.move(-3-speed, 0);
			}
			if ((s_pirog.getPosition().x > s_popt1.getPosition().x && s_pirog.getPosition().x - 50 < s_popt1.getPosition().x))
			{
				s_pirog.move(-3-speed, 0);
			}
			if ((s_pirog.getPosition().x < s_popt1.getPosition().x && s_pirog.getPosition().x + 50 > s_popt1.getPosition().x))
			{
				s_pirog.move(-3- speed, 0);
			}
			window.draw(timerText);
			window.draw(count_pirog);
		}

		if (put >= intpirog)
		{
			s_bus.move(-s_busSpeed, s_busSpeed / 2);
			window.draw(win);
			window.draw(s_bus);
			if (s_bus.getPosition().y > 400.0f)
			{
				s_busSpeed = 0.0f;
				isGameEnd = true;
			}
		}
		if (isGameEnd)
		{
			herosprite.move(0.15f, 0);
		}
		if (herosprite.getPosition().x < s_bus.getPosition().x - 30.0f)
		{
			window.draw(herosprite);
		}
		else {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
					if (button.getGlobalBounds().contains(mousePos)) {
						restart = true;
						buttonText.setString("Restart!");
						window.close();
					}
				}
			}
			window.draw(button);
			window.draw(buttonText);
		}
		if (isGameOver && put < intpirog)
		{
			window.draw(s_end);
			run = false;
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
					if (button.getGlobalBounds().contains(mousePos)) {
						restart = true;
						buttonText.setString("Restart!");
						window.close();
					}
				}
			}
			window.draw(button);
			window.draw(buttonText);
		}


		window.display();
	}

	
}


void menu()
{
	setlocale(LC_ALL, "Russian");
	RenderWindow window(VideoMode(800, 600), "menu");

	Font font;
	font.loadFromFile("srift.ttf");

	Text title;
	title.setFont(font);
	title.setString("FROGGER");
	title.setCharacterSize(40);
	title.setFillColor(Color::White);
	title.setPosition(280, 100);
	Text rules;
	rules.setFont(font);
	rules.setString("Rules of the game:\n jump over pop its not to touch spinners\n collect pies.\n By collecting "+ std::to_string(intpirog)+ " pies you win");
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
						game_run();
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