#include "../include/wins.hpp"
#include "../include/button.hpp"

void main_menu () {
	// рисуем окошко
	sf::RenderWindow menu(sf::VideoMode(600, 300), "Chess!", sf::Style::Titlebar | sf::Style::Close);
	menu.setFramerateLimit(60);
	menu.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width) / 2 - 300, (sf::VideoMode::getDesktopMode().height) / 2 - 150));

	// грузим шрифтец
	sf::Font serif_font;

	// если ебаный шрифт не захочет грузиться, то мы выходим НАХУЙ
	if (!serif_font.loadFromFile("TNR.ttf"))
		return;

	// текст
	sf::Text title;
	title.setFont(serif_font);
	title.setCharacterSize(72);
	title.setFillColor(sf::Color(215, 253, 236));
	title.setString(L"Шахматы");
	title.setPosition(140.f, 10.f);

	// кнопка 

	Button start(L"Начать", sf::Vector2f(140.f, 70.f), 32, sf::Color(215, 253, 236), sf::Color(56, 61, 59));
	
	start.setFont(serif_font);
	//sf::Vector2f textpos((300.f - start.getGlobalBounds().width), (10.f + title.getGlobalBounds().height + (300.f - (10.f + title.getGlobalBounds().height)/2)));
	start.setPosition(sf::Vector2f(230.f, 175.f));

	// главный цикл

	while (menu.isOpen()) {
		sf::Event event;
		while (menu.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				menu.close();
				break;
			case sf::Event::MouseMoved:
				if (start.isMouseOver(menu)) start.setBackColor(sf::Color(242, 184, 128));
				else start.setBackColor(sf::Color(215, 253, 236));
				break;
			case sf::Event::MouseButtonPressed:
				start.scale(0.66, 0.66);
				menu.close();
				chessboard();
				break;
			default:
				break;
			}
		}
		menu.clear(sf::Color(56, 61, 59));

		menu.draw(title);

		start.draw_to(menu);

		menu.display();
	}
}
