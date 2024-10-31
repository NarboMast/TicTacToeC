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
    char getValue(int row, int col);
    bool checkWin(char player);
};



#endif //BOARD_H
