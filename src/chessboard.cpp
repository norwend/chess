#include "../include/wins.hpp"

void chessboard () {
	// настройки окна
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow board(sf::VideoMode(1000, 700), "Chess!", sf::Style::Titlebar | sf::Style::Close, settings);
	board.setFramerateLimit(60);

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
