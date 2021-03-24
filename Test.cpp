//
// Created by Liron on 15/03/2021.
//

#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace doctest;
using namespace ariel;
using namespace std;

Board board;
TEST_CASE("Good code") {
CHECK_NOTHROW(board.post(10,20,Direction::Horizontal,"zxcvb"));
CHECK(board.read(10,20,Direction::Horizontal,0)==string(""));
CHECK(board.read(10,20,Direction::Horizontal,1)==string("z"));
CHECK(board.read(10,20,Direction::Horizontal,2)==string("zx"));
CHECK(board.read(10,20,Direction::Horizontal,3)==string("zxc"));
CHECK(board.read(10,20,Direction::Horizontal,4)==string("zxcv"));
CHECK(board.read(10,20,Direction::Horizontal,5)==string("zxcvb"));

CHECK(board.read(10,20,Direction::Vertical,0)==string(""));
CHECK(board.read(10,20,Direction::Vertical,1)==string("z"));

CHECK_NOTHROW(board.post(11,21,Direction::Horizontal,"down"));
CHECK(board.read(11,20,Direction::Horizontal,1)==string("_"));
CHECK(board.read(11,20,Direction::Horizontal,0)==string(""));
CHECK(board.read(11,20,Direction::Horizontal,2)==string("_d"));
CHECK(board.read(11,20,Direction::Horizontal,3)==string("_do"));
CHECK(board.read(11,20,Direction::Horizontal,4)==string("_dow"));
CHECK(board.read(11,20,Direction::Horizontal,5)==string("_down"));
CHECK(board.read(11,21,Direction::Horizontal,0)==string(""));
CHECK(board.read(11,21,Direction::Horizontal,1)==string("d"));
CHECK(board.read(11,21,Direction::Horizontal,2)==string("do"));
CHECK(board.read(11,21,Direction::Horizontal,3)==string("dow"));
CHECK(board.read(11,21,Direction::Horizontal,4)==string("down"));
CHECK_NOTHROW(board.post(11,21,Direction::Vertical,"opi"));
CHECK(board.read(10,21,Direction::Vertical,2)==string("xo"));
CHECK(board.read(10,21,Direction::Vertical,3)==string("xop"));
CHECK(board.read(10,21,Direction::Vertical,4)==string("xopi"));
CHECK(board.read(10,21,Direction::Horizontal,4)==string("xcvb"));
CHECK_NOTHROW(board.post(100,200, Direction::Horizontal,"abcd"));
CHECK(board.read(99, 201, Direction::Vertical,3)==string("_b_"));
CHECK_NOTHROW(board.post(99, 202, Direction::Vertical, "xyz"));
CHECK(board.read(100, 200, Direction::Horizontal, 6)==string("abyd__"));

}
