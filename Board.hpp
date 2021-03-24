//
// Created by Liron on 15/03/2021.
//

#ifndef UNTITLED4_BOARD_HPP
#define UNTITLED4_BOARD_HPP
#include "string"
using namespace std;
#include "Direction.hpp"
using ariel::Direction;
namespace ariel {
    class Board {
    private:
        char** boardMath;

        unsigned int size = 50;
       void addsize(unsigned int row, unsigned int column, unsigned int length);
    public:
        void post(unsigned int row, unsigned int column, Direction way, string ad);
        string read(unsigned int row, unsigned int column, Direction way, unsigned int length);
        void show();
        ~Board();
        Board();

        void deleteMatrix(unsigned int size) ;
    };

}

#endif //UNTITLED4_BOARD_HPP
