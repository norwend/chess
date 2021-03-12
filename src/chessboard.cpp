#include "../include/windowlist.hpp"
#include "../include/figure.hpp"
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

	sf::Image pieces;
	pieces.loadFromFile("chesspieces.png");
	Pawn pawn1(0, 0, 0, pieces);
	Pawn pawn2(1, 0, 1, pieces);

	//главный цикл
	while (board.isOpen()) {
		sf::Event event;
		while (board.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				board.close();
				break;
			
			case sf::Event::MouseButtonPressed:
				break;

			case sf::Event::MouseButtonReleased:
				break;
				
			default:
				break;
			}
		}
		board.clear(sf::Color(247, 197, 159));

		board.draw(background);
		pawn1.draw_to(board);
		pawn2.draw_to(board);
		board.display();
	}
	// после закрытия окна уходим в меню
	main_menu();
}
