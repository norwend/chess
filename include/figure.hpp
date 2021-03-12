#include "clickable.hpp"
#define SIZE 320

class Figure : public Clickable {
public:
	int getPos();
	void move();	
protected:
	Figure() {
	}
	sf::RectangleShape rect;
	bool color_;
	int pos_;
};

class Pawn : public Figure {
public:
	Pawn(int col, int row, bool color, sf::Image pieces) {
		if (color == 1) texture_.loadFromImage(pieces, sf::IntRect(1600, 0, SIZE, SIZE));
		if (color == 0) texture_.loadFromImage(pieces, sf::IntRect(1600, 320, SIZE, SIZE));
		rect.setSize(sf::Vector2f(75, 75));
		rect.setPosition(sf::Vector2f(50 + col*75, 53 + row * 75));
		rect.setTexture(&texture_);
	}
	void draw_to(sf::RenderWindow& window) {
		window.draw(rect);
	}
private:

	sf::Texture texture_;
};