#include "../include/window_drawer.hpp"

void chessboard () {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow board(sf::VideoMode(1000, 700), "Chess!", sf::Style::Titlebar | sf::Style::Close, settings);
	board.setFramerateLimit(60);

	sf::Texture bgtext;
	bgtext.loadFromFile("chessboard.png");

	sf::RectangleShape background(sf::Vector2f(700.f, 700.f));

	background.setTexture(&bgtext);

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
	main_menu();
}

int main () {
	main_menu();
	return 0;
}





// эта хуйня виснет шо пиздец. пока что отбросил, а ведь могло быть пиздец красиво...

//for (int i = 0; i < 64; ++i) board.draw(cells[i]);
	// sf::RectangleShape cells[63];

	// for (int i = 0; i < 8; ++i) {
	// 	for (int j = 0; j < 8; ++j) {
	// 		cells[(i*8)+j] = sf::RectangleShape(sf::Vector2f(75.f, 75.f));
	// 		cells[(i*8)+j].setPosition(40+(j*70), 640-(i*80));
	// 	}
	// }
	// for (int i = 0; i < 63; ++i) {
	// 	cells[i].setFillColor(sf::Color(230, 57, 70));
	// 	cells[i].setOutlineColor(sf::Color(56, 61, 59));
	// 	cells[i].setOutlineThickness(5.f);
	// 	cells[i+1].setFillColor(sf::Color(242, 184, 128));
	// 	cells[i+1].setOutlineColor(sf::Color(56, 61, 59));
	// 	cells[i+1].setOutlineThickness(5.f);
	// 	if (i!=62) ++i;
	// }
