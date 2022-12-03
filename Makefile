CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -g -MMD -Werror=vla 
EXEC = biquadris
OBJECTS = abstractblock.o cell.o iblock.o lblock.o levelone.o main.o oblock.o tblock.o zblock.o board.o game.o jblock.o sblock.o subject.o window.o textobserver.o graphobserver.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS} # ignore errors

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
