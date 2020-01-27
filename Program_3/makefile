CC=g++
EXE_FILE=playZooTycoon

all: $(EXE_FILE)

$(EXE_FILE): zooTycoon.o zoo.o monkey.o seaOtter.o sloth.o animal.o
	$(CC) zooTycoon.o zoo.o monkey.o seaOtter.o sloth.o animal.o -o $(EXE_FILE)

zooTycoon.o: zooTycoon.cpp
	$(CC) -c zooTycoon.cpp

zoo.o: zoo.cpp zoo.hpp monkey.hpp seaOtter.hpp sloth.hpp animal.hpp
	$(CC) -c zoo.cpp

monkey.o: monkey.cpp zoo.hpp monkey.hpp seaOtter.hpp sloth.hpp animal.hpp
	$(CC) -c monkey.cpp

seaOtter.o: seaOtter.cpp zoo.hpp monkey.hpp seaOtter.hpp sloth.hpp animal.hpp
	$(CC) -c seaOtter.cpp

sloth.o: sloth.cpp zoo.hpp monkey.hpp seaOtter.hpp sloth.hpp animal.hpp
	$(CC) -c sloth.cpp

animal.o: animal.cpp zoo.hpp monkey.hpp seaOtter.hpp sloth.hpp animal.hpp
	$(CC) -c animal.cpp

clean:
	rm -f *.out *.o $(EXE_FILE)
