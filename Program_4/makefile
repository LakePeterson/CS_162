CXX=g++
EXE=playHuntTheWumpus
SRC=arrowEvent.cpp bats.cpp event.cpp game.cpp gold.cpp huntTheWumpus.cpp pit.cpp room.cpp wumpus.cpp
HEADERS=arrowEvent.hpp bats.hpp event.hpp game.hpp gold.hpp pit.hpp room.hpp wumpus.hpp

$(EXE): $(SRC) $(HEADERS)
	$(CXX) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE) *.o *.out
