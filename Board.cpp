//
// Created by Liron on 15/03/2021.
//

#include "string"
#include "Board.hpp"
#include <iostream>

using namespace std;
using namespace ariel;
const int size = 50;

void Board::post(unsigned int row, unsigned int column, Direction way, string ad) {
    if (row < 0) {
        throw std::invalid_argument("column and row cannot be negative");
    }
    if (column < 0) {
        throw std::invalid_argument("column and row cannot be negative");// "column and row cannot be negative";
    }
    addsize(row, column, ad.length());
    int ADSize = ad.length();
    if (way == Direction::Vertical) {
        for (unsigned int k = 0; k < ADSize; ++k) {
            boardMath[row + k][column] = ad[k];
        }
    }
    if (way == Direction::Horizontal) {
        for (unsigned int k = 0; k < ADSize; ++k) {
            boardMath[row][column + k] = ad[k];
        }
    }

}

string Board::read(unsigned int row, unsigned int column, Direction way, unsigned int length) {
    string ans;
    if (way == Direction::Horizontal) {
        for (unsigned int len = column; len < column + length; ++len) {
            if (len < size && row < size) {
                ans += boardMath[row][len];
            } else {
                ans += '_';
            }
        }

    }
    if (way == Direction::Vertical) {
        for (unsigned int len = row; len < row + length; ++len) {
            if (column < size && len < size) {
                ans += boardMath[len][column];
            } else {
                ans += '_';
            }
        }
    }

    return ans;
}

void Board::show() {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << boardMath[i][j];
        }
        cout << endl;

    }

}

Board::Board() {//init for _
    //  size = 50;

    boardMath = new char *[size];
    for (int i = 0; i < size; ++i) {
        boardMath[i] = new char[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            boardMath[i][j] = '_';
        }
    }
}

void Board::addsize(unsigned int row, unsigned int column, unsigned int length) {
    unsigned int oldSize = size;
    if (row + length - 1 > oldSize || column + length - 1 > oldSize) {
        if (row + length - 1 > column + length - 1) {
            size = row + length;
        }
        if (row + length - 1 < column + length - 1) {
            size = column + length;
        }

        char **newMath = new char *[size];
        for (int i = 0; i < size; ++i) {
            newMath[i] = new char[size];
        }
        //after the size++ and copy what happnd before
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i < oldSize && j < oldSize) {
                    newMath[i][j] = boardMath[i][j];
                } else {
                    newMath[i][j] = '_';
                }
            }
        }

        deleteMatrix(oldSize);
        boardMath = newMath;
    }
}

Board::~Board() {
//    deleteMatrix(size);
}

void Board::deleteMatrix(unsigned int size)  {
    int i;
    for ( i=0; i < size; i++){
        delete [] boardMath[i];
    }
   // delete *boardMath;
}

