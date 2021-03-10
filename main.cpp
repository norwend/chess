#include <SFML/Graphics.hpp>

class Figure {
	bool color;
	short type;
};

class Board {};

class Player {
	bool color;
	int score;
};

class Cell {
	short number;
	bool color;
};

int main () {
	sf::RenderWindow win(sf::VideoMode(800, 600), "Chess");
	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
		}
	}
	win.clear();
	win.display();
	return 0;
}