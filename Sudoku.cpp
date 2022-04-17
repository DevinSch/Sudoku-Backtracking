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
  //Solver test;
  std::string file = argv[1];
  Sudoku.readBoard(file);

  Sudoku.printBoard();
  int t, p;
  std::cout << "Missing vals " << Sudoku.stillMissingVals(t,p) << "\n";
  std::cout << "check local " << Sudoku.checkLocal('1', 0, 0) << "\n";
  std::cout << "Check Horizontal " << Sudoku.checkHorizontal('2', 0) << "\n";
  std::cout << "Check vertical " << Sudoku.checkVertical('1', 0) << "\n";

  //std::cout << Sudoku.checkConstraints(temp, 0, 0) << "\n\n";


  if (Sudoku.backTracking() == true) {
    std::cout << "We did it!\n";
    Sudoku.printBoard();
  } else {
    std::cout << "Something went wrong\n";
    Sudoku.printBoard();
  }

  std::cout << "Test Complete\n";
}
