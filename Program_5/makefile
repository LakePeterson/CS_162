CXX=g++
EXE=playMaze

SRC=instructor.cpp intrepidStudent.cpp main.cpp maze.cpp mazeLevel.cpp mazeLocation.cpp mazePerson.cpp openSpace.cpp ta.cpp wall.cpp
HEADERS=instructor.hpp intrepidStudent.hpp maze.hpp mazeLevel.hpp mazeLocation.hpp mazePerson.hpp openSpace.hpp ta.hpp wall.hpp

$(EXE): $(SRC) $(HEADERS)
	$(CXX) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE) *.o *.out
