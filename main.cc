#include "board.h"
#include "cell.h"
#include "iblock.h"


int main() {
    Board b;
    b.board[0][0] = std::make_unique<Cell>('A');
    IBlock i{&b};
    b.printBoard();
    i.rotate(true);
    b.printBoard();
    i.rotate(true);
    b.printBoard();
    i.rotate(false);
    b.printBoard();
}