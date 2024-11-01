//
// Created by narbo on 10/31/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <jni.h>
#include <vector>


class Board {
private:
    std::vector<std::vector<char>> board;
    bool whiteTurn = true;
    int dimensionC;
public:
    explicit Board(int dimensionJ);
    void makeMove(int row, int col);
    char getValue(int row, int col);
    bool checkWin(char player);
    bool checkDraw();
};



#endif //BOARD_H
