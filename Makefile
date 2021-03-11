all: compile mkapp
compile:
	g++ main.cpp -L /usr/local/lib/ -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-network -o chess
mkapp:
	mkdir -p ./Chess.app/Contents/MacOS
	cp ./Info.plist ./Chess.app/Info.plist
	cp ./chess ./Chess.app/Contents/MacOS	
clean:
	rm -r Chess.app chess
