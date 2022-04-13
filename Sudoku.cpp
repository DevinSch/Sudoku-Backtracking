// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: April 12th, 2022
// Assignment: 3 - Sudoku
#include <iostream>
#include "./Game.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "No file given!\n";
    std::cout << "Please enter a file name after ./Sudoku 'fileName' \n";
    exit(0);
  }

  Board Sudoku;
  std::string file = argv[1];
  Sudoku.readBoard(file);

  Sudoku.printBoard();

  std::cout << "Test Complete\n";
}
