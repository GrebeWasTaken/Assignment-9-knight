#include <iostream>
#include <iomanip>

using namespace std;

bool onBoard(int row, int col)
{
  return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void findKnightPath(int row, int col, int movesLeft){
  if (!onBoard(row, col)){
    return;
  }

  if (movesLeft == 0){
    cout << "(" << row << ", " << col << ")" << endl;

    return;
  }

  int rowMoves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int colMoves[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

  
}

int main()
{
  int row, col, N;
  cout << "Enter starting row (0-7): ";
  cin >> row;
  cout << "Enter starting column (0-7): ";
  cin >> col;
  cout << "Enter number of moves: ";
  cin >> N;
}
