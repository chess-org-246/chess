CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -g -MMD -Werror=vla
EXEC = biquadris 
OBJECTS = cell.o board.o abstractblock.o iblock.o sblock.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS} # ignore errors

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
