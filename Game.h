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

  private:
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
