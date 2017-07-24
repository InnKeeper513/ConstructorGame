CXX = g++-5
CXXFLAGS = -std=c++14 -MMD -Werror=vla
EXEC = ctor
OBJECTS = main.o Address.o Tile.o Builder.o Dice.o Path.o Subject.o Board.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
