CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -g -MMD -Werror=vla
EXEC = biquadris 
OBJECTS = masks.o trie.o eventmgr.o match.o abstractblock.o cell.o iblock.o lblock.o levelzero.o levelone.o leveltwo.o levelthree.o levelfour.o main.o oblock.o tblock.o zblock.o board.o game.o jblock.o sblock.o
>>>>>>> 8e77b08 (refactor to create next block)
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS} # ignore errors

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
