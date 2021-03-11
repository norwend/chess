#include <SFML/Graphics.hpp>

class Button {
public:
	Button () {}
	Button (std::wstring txt, sf::Vector2f size, int char_size, sf::Color bgcolor, sf::Color text_color) {
		text.setString(txt);
		text.setCharacterSize(char_size);
		text.setFillColor(text_color);
		
		button.setSize(size);
		button.setFillColor(bgcolor);
	}

	void setFont (sf::Font& font) {
		text.setFont(font);
	}

	void setCharacterSize (int size) {
		text.setCharacterSize(size);
	}

	void setBackColor (sf::Color color) {
		button.setFillColor(color);
	}

	void setTextColor (sf::Color color) {
		text.setFillColor(color);
	}

	sf::FloatRect getGlobalBounds() {
		return button.getGlobalBounds();
	}

	void setPosition (sf::Vector2f pos) {
		button.setPosition(pos);

		float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);

		text.setPosition(xPos, yPos);
	}

	void draw_to (sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}

	void scale (float a, float b) {
		button.scale(a, b);
		text.scale(a, b);
	}

	bool isMouseOver (sf::RenderWindow& window) {
		float mouse_x = sf::Mouse::getPosition(window).x;
		float mouse_y = sf::Mouse::getPosition(window).y;

		float btn_pos_x1 = button.getPosition().x;
		float btn_pos_x2 = button.getGlobalBounds().width + btn_pos_x1;

		float btn_pos_y1 = button.getPosition().y;
		float btn_pos_y2 = button.getGlobalBounds().height + btn_pos_y1;

		if (mouse_x < btn_pos_x2 && mouse_x > btn_pos_x1 && mouse_y > btn_pos_y1 && mouse_y < btn_pos_y2) return true;

		return false;
	}
private:
	sf::RectangleShape button;
	sf::Text text;
};

 