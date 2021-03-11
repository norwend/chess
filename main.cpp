#include <SFML/Graphics.hpp>

class Figure {
	bool color;
	short type;
	short pos;
};

class Board {};

class Player {
	bool color;
	int score;
};

void draw_board() {
	
}

int main () {
	sf::Window win(sf::VideoMode(800, 600), "Chess");
	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
		}
	}
	return 0;
}