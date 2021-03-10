all:
	g++ main.cpp -L /usr/local/lib/ -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-network -o chess
