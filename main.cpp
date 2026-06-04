#include <iomanip>
#include <iostream>

using namespace std;

bool onBoard(int row, int col)
{
  return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void findKnightPath(int row, int col, int movesLeft, int counts[8][8], int pathRows[], int pathCols[], int pathLength)
{
  if (!onBoard(row, col)) {
    return;
  }

  pathRows[pathLength] = row;
  pathCols[pathLength] = col;

  pathLength++;

  if (movesLeft == 0) {
    cout << "(" << row << ", " << col << ")" << endl;

    counts[row][col]++;

    return;
  }

  int rowMoves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int colMoves[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

  for (int i = 0; i < 8; i++) {
    findKnightPath(row + rowMoves[i], col + colMoves[i], movesLeft - 1, counts);
  }
}

void printBoard(int counts[8][8])
{
  cout << endl;
  cout << "Diagram" << endl;

  cout << "   ";
  for (int col = 0; col < 8; col++) {
    cout << setw(5) << col;
  }
  cout << endl;

  for (int row = 0; row < 8; row++) {
    cout << row << "  ";

    for (int col = 0; col < 8; col++) {
      cout << setw(5) << counts[row][col];
    }

    cout << endl;
  }
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

  int counts[8][8];

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      counts[r][c] = 0;
    }
  }

  int* pathRows = new int[N + 1];
  int* pathCols = new int[N + 1];

  cout << endl;
  cout << "Paths:" << endl;

  findKnightPath(row, col, N, counts);

  printBoard(counts);
}
