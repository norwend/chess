#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale>

void main_menu();
void chessboard();

class Figure {
	bool color;
	short type;
	short pos;
};

class Player {
	bool color;
	int score;
};
