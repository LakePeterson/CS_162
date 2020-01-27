CC=g++
EXE_FILE=goFishGame

all: $(EXE_FILE)

$(EXE_FILE): game.o player.o hand.o deck.o card.o game.hpp game.cpp player.hpp player.cpp hand.hpp hand.cpp deck.hpp deck.cpp card.hpp card.cpp
	$(CC) game.o player.o hand.o deck.o card.o goFish.cpp -o $(EXE_FILE)

muldiv.o: game.hpp game.cpp player.hpp player.cpp hand.hpp hand.cpp deck.hpp deck.cpp card.hpp card.cpp
	$(CC) -c game.cpp player.cpp hand.cpp deck.cpp card.cpp
