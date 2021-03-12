all: compile mkapp
compile:
	g++ ./src/main.cpp ./src/menu.cpp ./src/chessboard.cpp ./include/*.* -L /usr/local/lib/ -lsfml-window -lsfml-graphics -lsfml-system
	mv a.out chess
	cp ./contents/TNR.ttf ./TNR.ttf
	cp ./contents/chessboard.png ./chessboard.png
	rm ./include/button.hpp.gch ./include/wins.hpp.gch 
mkapp:
	mkdir -p ./Chess.app/Contents/MacOS
	cp ./contents/Info.plist ./Chess.app/Info.plist
	cp ./chess ./Chess.app/Contents/MacOS/chess
	mv ./TNR.ttf ./Chess.app/Contents/MacOS/TNR.ttf
	cp ./chessboard.png ./Chess.app/Contents/MacOS/chessboard.png
clean:
	rm -r Chess.app chess TNR.ttf chessboard.png
