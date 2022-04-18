// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: April 12th, 2022
// Assignment: 3 - Sudoku
#include <iostream>
#include <fstream>
#include <iomanip>

#define size 9

void printBoard(int square[size][size]);
void readBoard(std::string fileName, int square[size][size]);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "No file given!\n";
    std::cout << "Please enter a file name after ./Sudoku 'fileName' \n";
    exit(0);
  }

  std::string file = argv[1];
  int game[size][size];
  readBoard(file, game);

  printBoard(game);
  /*
  int t, p;
  std::cout << "Missing vals " << Sudoku.stillMissingVals(t,p) << "\n";
  std::cout << "check local " << Sudoku.checkLocal('1', 0, 0) << "\n";
  std::cout << "Check Horizontal " << Sudoku.checkHorizontal('2', 0) << "\n";
  std::cout << "Check vertical " << Sudoku.checkVertical('1', 0) << "\n";

  //std::cout << Sudoku.checkConstraints(temp, 0, 0) << "\n\n";


  if (Sudoku.SolveGame() == true) {
    std::cout << "We did it!\n";
    Sudoku.printBoard();
  } else {
    std::cout << "Something went wrong\n";
    Sudoku.printBoard();
  }*/

  std::cout << "Test Complete\n";
}

void readBoard(std::string fileName, int square[size][size]) {
  std::ifstream fin;
  fin.open(fileName);

  while(!fin.eof()) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        fin >> square[i][j];
      }
    }
  }
  fin.close();
}

void printBoard(int square[size][size]) {
  int count = 0;
  int count2 = 0;
  std::setw(3);
  std::cout << "|";
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (count == 3) {
        std::cout << "|";
        count = 0;
      }
      if (square[i][j] == 0) {
        std::cout << "   ";
      } else {
        std::cout << " " << square[i][j] << " " ;
      }
      count++;
    }
    count2 ++;
    std::cout << "| \n";
    if (count2 == 3) {
      for(int k = 0; k <= size; k++) {
        std::cout << "---";
      }
      std::cout << "\n";
      count2 = 0;
    }
  }
}
