#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>

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
	sf::RenderWindow win(sf::VideoMode(800, 600), "Chess");
	sf::Font gothic_font;
	sf::Font serif_font;
	if (gothic_font.loadFromFile("../contents/Cloister.ttf") || serif_font.loadFromFile("../contents/Alice.ttf"))
		return 1;
	win.setFramerateLimit(60);
	while (win.isOpen()) {

		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
		}
		win.clear(sf::Color::White);
		win.display();
	}
	return 0;
}