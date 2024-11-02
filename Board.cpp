//
// Created by narbo on 10/31/2024.
//

#include "Board.h"

Board::Board(const int dimensionJ) {
    dimensionC = dimensionJ;
    board = std::vector<std::vector<char>>(dimensionJ, std::vector<char>(dimensionJ, ' '));
}

void Board::makeMove(int row, int col) {
    if (board[row][col] == ' ') {
        if (whiteTurn) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }
        whiteTurn = !whiteTurn;
    }
}

char Board::getValue(int row, int col) {
    return board[row][col];
}

bool Board::checkWin(char player) {
    for (int i = 0; i < dimensionC; i++) {
        bool rowWin = true;
        for (int j = 0; j < dimensionC; j++) {
            if(board[i][j] != player) {
                rowWin = false;
                break;
            }
        }
        if(rowWin) {
            return true;
        }
    }

    for(int j = 0; j < dimensionC; j++) {
        bool colWin = true;
        for(int i = 0; i < dimensionC; i++) {
            if(board[i][j] != player) {
                colWin = false;
                break;
            }
        }
        if(colWin) {
            return true;
        }
    }

    bool diagonalWin = true;
    for (int i = 0; i < dimensionC; i++) {
        if (board[i][i] != player) {
            diagonalWin = false;
            break;
        }
    }
    if (diagonalWin) {
        return true;
    }

    diagonalWin = true;
    for (int i = 0; i < dimensionC; i++) {
        if (board[i][dimensionC - 1 - i] != player) {
            diagonalWin = false;
            break;
        }
    }
    return diagonalWin;
}

bool Board::checkDraw() {
    for (int i = 0; i < dimensionC; i++) {
        for (int j = 0; j < dimensionC; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Board::capture(int row, int col) {
    if (board[row][col] != ' ') {
        if (whiteTurn) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }
        whiteTurn = !whiteTurn;
    }
}
