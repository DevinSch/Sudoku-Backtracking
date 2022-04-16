#include <iostream>

using namespace std;

int main() {

  int row = 2;
  int col = 4;

  int row2 = row - row % 3;
  int col2 = col - col % 3;

  cout << "row2 = " << row2;
  cout << "\ncol2 = " << col2;
  cout << "\ntest complete\n";
}
