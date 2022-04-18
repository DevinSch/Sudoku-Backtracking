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
bool missingValues(int square[size][size], int& row, int& col);
bool checkConstraints(int square[size][size], int row, int col, int val);
bool checkHorizontal(int square[size][size], int row, int val);
bool checkVertical(int square[size][size], int col, int val);
bool checkLocal(int square[size][size], int row, int col, int val);
bool backTracking(int square[size][size]);

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

bool missingValues(int square[size][size], int& row, int& col) {
    for (row = 0; row < size; row++)
        for (col = 0; col < size; col++)
            if (square[row][col] == 0)
                return true;
    return false;
}

bool checkConstraints(int square[size][size], int row, int col, int val) {
    return !checkHorizontal(square, row, val)
           && !checkVertical(square, col, val)
           && !checkLocal(square, row - row % 3,
                         col - col % 3, val)
           && square[row][col] == 0;
}

bool checkHorizontal(int square[size][size], int row, int val) {
    for (int i = 0; i < size; i++)
        if (square[row][i] == val)
            return true;
    return false;
}

bool checkVertical(int square[size][size], int col, int val) {
    for (int i = 0; i < size; i++)
        if (square[i][col] == val)
            return true;
    return false;
}

bool checkLocal(int square[size][size], int row, int col, int val) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (square[i + row][j + col] == val)
                return true;
    return false;
}

bool backTracking(int square[size][size]) {
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!missingValues(square, row, col))
        // success!
        return true;

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {

        // Check if looks promising
        if (checkConstraints(square, row, col, num))
        {

            // Make tentative assignment
            square[row][col] = num;

            // Return, if success
            if (backTracking(square))
                return true;

            // Failure, unmake & try again
            square[row][col] = 0;
        }
    }

    // This triggers backtracking
    return false;
}
