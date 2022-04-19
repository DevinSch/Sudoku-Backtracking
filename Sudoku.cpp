// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: April 12th, 2022
// Assignment: 3 - Sudoku
#include <iostream>
#include <fstream>
#include <iomanip>
#define size 9 // All Sudoku games are a 9x9 grid

//*****************************Functions***************************************
// Display the current Sudoku game board
void printBoard(int square[size][size]);

// Read in the game to solve from a file, file given as argument
void readBoard(std::string fileName, int square[size][size]);

// Checks for any missing values, returning row and col of next missing value
bool missingValues(int square[size][size], int& row, int& col);

// Checks all contstraints
bool checkConstraints(int square[size][size], int row, int col, int val);

// Check is the same value is alreay within that row
bool checkHorizontal(int square[size][size], int row, int val);

// Check is the same value is alreay within that col
bool checkVertical(int square[size][size], int col, int val);

// Checks the 3x3 grid to see if the value as already been used
bool checkLocal(int square[size][size], int row, int col, int val);

// BackTracking search, calls checkConstraints to solve the puzzle
bool backTracking(int square[size][size]);
//*****************************Functions***************************************


int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "No file given!\n";
    std::cout << "Please enter a file name after ./Sudoku 'fileName' \n";
    exit(0);
  }

  std::string file = argv[1];
  int game[size][size];
  readBoard(file, game);
  std::cout << "Game board to search:\n";
  printBoard(game);

  if (backTracking(game) == true) {
    std::cout << "Solution found!\n\n";
    printBoard(game);
  } else {
    std::cout << "Something went wrong\n";
    std::cout << "No solution was found for this board\n";
    printBoard(game);
  }
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
    count2++;
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

bool missingValues(int square[size][size], int& row, int& col) {
  for (row = 0; row < size; row++) {
    for (col = 0; col < size; col++) {
      if (square[row][col] == 0) {
        return true;
      }
    }
  }
  return false;
}

bool checkConstraints(int square[size][size], int row, int col, int val) {
  // Find the start of the local square, check local then checks 3x3 from there
  int row2 = row - row % 3;
  int col2 = col - col % 3;
  return !checkHorizontal(square, row, val)
      && !checkVertical(square, col, val)
      && !checkLocal(square, row2, col2, val);
}

bool checkHorizontal(int square[size][size], int row, int val) {
  for (int i = 0; i < size; i++) {
    if (square[row][i] == val) {
      return true;
    }
  }
  return false;
}

bool checkVertical(int square[size][size], int col, int val) {
  for (int i = 0; i < size; i++) {
    if (square[i][col] == val) {
      return true;
    }
  }
  return false;
}

bool checkLocal(int square[size][size], int row, int col, int val) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (square[i + row][j + col] == val) {
        return true;
      }
    }
  }
  return false;
}

bool backTracking(int square[size][size]) {
  int row, col;

  if (missingValues(square, row, col) == false) {
    return true;
  } else {
    for (int num = 1; num <= 9; num++) {
      if (checkConstraints(square, row, col, num) == true) {
        square[row][col] = num;
        if (backTracking(square) == true) {
          return true;
        } else {
          square[row][col] = 0;
        }
      }
    }
  }
  return false;
}
