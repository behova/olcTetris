CC = g++
CFLAGS = -g

all: clean tetris

clean:
	#clean tetris and any .o files
	rm -f tetris *.o

olc.o:
	$(CC) olcPixelGameEngine.cpp -c -o olc.o

tetrominos.o: olc.o
	$(CC) Tetrominos.cpp -c -o tetrominos.o

logic.o: olc.o tetrominos.o
	$(CC) Logic.cpp -c -o logic.o

board.o: olc.o tetrominos.o logic.o
	$(CC) Board.cpp -c -o board.o

main.o: olc.o tetrominos.o logic.o board.o
	$(CC) main.cpp -c -o main.o

tetris: olc.o tetrominos.o logic.o board.o main.o
	$(CC) olc.o tetrominos.o logic.o board.o main.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -o tetris
