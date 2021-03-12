#include "clickable.hpp"

class Button : public Clickable {
public:
	Button () {}
	Button (std::wstring txt, sf::Vector2f size, int char_size, sf::Color bgcolor, sf::Color text_color) {
		text.setString(txt);
		text.setCharacterSize(char_size);
		text.setFillColor(text_color);
		
		rect.setSize(size);
		rect.setFillColor(bgcolor);
	}

	void setFont (sf::Font& font) {
		text.setFont(font);
	}

	void setCharacterSize (int size) {
		text.setCharacterSize(size);
	}

	void setBackColor (sf::Color color) {
		rect.setFillColor(color);
	}

	void setTextColor (sf::Color color) {
		text.setFillColor(color);
	}

	sf::FloatRect getGlobalBounds() {
		return rect.getGlobalBounds();
	}

	void setPosition (sf::Vector2f pos) {
		rect.setPosition(pos);

		float xPos = (pos.x + rect.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + rect.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);

		text.setPosition(xPos, yPos);
	}

	void draw_to (sf::RenderWindow& window) {
		window.draw(rect);
		window.draw(text);
	}

	void scale (float a, float b) {
		rect.scale(a, b);
		text.scale(a, b);
	}

private:
	sf::Text text;
};

 