// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: April 12th, 2022
// Assignment: 3 - Sudoku
#include <fstream>
#include <iomanip>

class Board {
  public:
    Board() {}

    ~Board() {
      for (int i = 0; i < size; i++) {
        delete [] value[i];
      }
      delete [] value;
    }

    void readBoard(std::string fileName);

    void printBoard();

    bool backTracking();

    bool checkConstraints(char val, int row, int col) {
      //std::cout << "In checkConstraints" << row << col<<  "\n";
      int row2 = row - row % 3;
      int col2 = col - col % 3;
      if (checkLocal(val, row2, col2)) {
        return false;
      }
      if (checkVertical(val, row)) {
        return false;
      }
      if (checkHorizontal(val, col)) {
        return false;
      }  //std::cout << "Clear in: " << row << col << "\n";

      return true;
    }

    // Return true if the same val is in that same vertical line
    bool checkVertical(char val, int col) {
      //std::cout << "In cheackVertical\n";
      for (int i = 0; i < size; i++) {
        if (value[i][col] == val)
          return true;
      }
      return false;
    }

    // Return true if the same val is in that same Horizontal line
    bool checkHorizontal(char val, int row) {
      //std::cout << "In checkHorizontal\n";
      for (int i = 0; i < size; i++) {
        if (value[row][i] == val)
          return true;
      }
      return false;
    }

    // Return true if the same val is in that same local area of the board
    // Row and Col are the top left of the 3x3 section of the board
    bool checkLocal(char val, int row, int col) {
      //std::cout << "In checkLocal\n";
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (value[i+row][j+col] == val) {
            return true;
          }
        }
      }
      return false;
    }

    bool stillMissingVals(int& row, int& col) {
      for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
          if (value[row][col] == 'X') {
            //std::cout << "Still missing = " << row << col << "\n";
            return true;
          }
        }
      }
      return false;
    }

  //private:
    int size = 9;
    char** value = nullptr;
};

void Board::readBoard(std::string fileName) {
  char input;
  int size_of_game;
  std::ifstream fin;
  fin.open(fileName);

  fin >> size_of_game;
  size = size_of_game;

  value = new char*[size];
  for(int i = 0; i < size; i++) {
    value[i] = new char[size];
  }

  while(!fin.eof()) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        fin >> value[i][j];
      }
    }
  }
  fin.close();
}

void Board::printBoard() {
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
      if (value[i][j] == 'X') {
        std::cout << "   ";
      } else {
        std::cout << " " << value[i][j] << " " ;
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

bool Board::backTracking() {
  int row = 0;
  int col = 0;

  if(stillMissingVals(row, col) == false) {
    return true;
  } else {

    for (int current = 1; current <= 9; current++) {
      char temp = current+'0';
      //std::cout << "current = " << current << "\n";
      //std::cout << "Checking " << row << col << "\n";
      if (checkConstraints(temp, row, col)) {
            value[row][col] = temp;
            //std::cout << "Assinging value = " << value[row][col] << "\n";

            if(backTracking() == true) {
              return true;
            }
            // Try the next value
            value[row][col] = 'X';
      } // end if
    } // end for
    //return false;
  } // end else
  return false;
} // end backTracking
