CXX = g++
<<<<<<< HEAD
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -g -MMD -Werror=vla
EXEC = biquadris 
OBJECTS = trie.o eventmgr.o match.o abstractblock.o cell.o iblock.o lblock.o levelzero.o levelone.o leveltwo.o levelthree.o levelfour.o main.o oblock.o tblock.o zblock.o board.o game.o jblock.o sblock.o subject.o textobserver.o graphobserver.o window.o
=======
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -g -MMD -Werror=vla 
EXEC = biquadris
OBJECTS = abstractblock.o cell.o iblock.o lblock.o levelone.o main.o oblock.o tblock.o zblock.o board.o game.o jblock.o sblock.o subject.o window.o textobserver.o graphobserver.o 
>>>>>>> 663623f (Fixed graphics observer)
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS} # ignore errors

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
