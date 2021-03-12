#include "../include/windowlist.hpp"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700

void chessboard () {
	// настройки окна
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow board(sf::VideoMode(1000, 700), "Chess!", sf::Style::Titlebar | sf::Style::Close, settings);
	board.setFramerateLimit(60);

	board.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width) / 2 - WINDOW_WIDTH / 2 + 150,
		(sf::VideoMode::getDesktopMode().height) / 2 - WINDOW_HEIGHT / 2));

	// доска
	sf::Texture bgtext;
	bgtext.loadFromFile("chessboard.png");
	sf::RectangleShape background(sf::Vector2f(700.f, 700.f));
	background.setTexture(&bgtext);

	//главный цикл
	while (board.isOpen()) {
		sf::Event event;
		while (board.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				board.close();
		}
		board.clear(sf::Color(247, 197, 159));

		
		board.draw(background);

		board.display();
	}
	// после закрытия окна уходим в меню
	main_menu();
}
