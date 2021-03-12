#include <SFML/Graphics.hpp>

class Clickable {
public:
	void setPosition (sf::Vector2f pos) {
		rect.setPosition(pos);
	}
	bool isMouseOver (sf::RenderWindow& window) {
		float mouse_x = sf::Mouse::getPosition(window).x;
		float mouse_y = sf::Mouse::getPosition(window).y;

		float rect_pos_left = rect.getPosition().x;
		float rect_pos_right = rect.getGlobalBounds().width + rect_pos_left;

		float rect_pos_up = rect.getPosition().y;
		float rect_pos_down = rect.getGlobalBounds().height + rect_pos_up;

		if (mouse_x < rect_pos_right && mouse_x > rect_pos_left && mouse_y > rect_pos_up && mouse_y < rect_pos_down) 
			return true;
		
		return false;
	}
	void draw_to (sf::RenderWindow& window) {
		window.draw(rect);
	}
protected:
	Clickable() {}
	Clickable(sf::Vector2f size) {
		rect.setSize(size);
	}
	sf::RectangleShape rect;
};