#include <iostream>
#include <vector>

using namespace std;

// Checks if a queen can be placed at the given row and column.
bool queenCanBePlaced(int** queens, int n, int col, int row) {
    // Check the row
    for (int c = 0; c < n; c++)
        if (queens[row][c] == 1)
            return false;

    // Check lower diagonal (left to right)
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
        if (queens[r][c] == 1)
            return false;

    // Check upper diagonal (left to right)
    for (int r = row, c = col; r < n && c >= 0; r++, c--)
        if (queens[r][c] == 1)
            return false;

    return true;
}

// Returns the number of solutions for the N-Queens problem.
int countSolutions(int** queens, int n, int col) {
    int count = 0;

    if (n == col)
        return 1;

    for (int row = 0; row < n; row++) {
        if (queenCanBePlaced(queens, n, col, row)) {
            queens[row][col] = 1;
            count += countSolutions(queens, n, col + 1);
            queens[row][col] = 0;
        }
    }
    return count;
}

int nQueens(int n) {
    int** queens = new int*[n];

    // Initialize the board
    for (int i = 0; i < n; i++) {
        queens[i] = new int[n];
        for (int j = 0; j < n; j++)
            queens[i][j] = 0;
    }

    // Count the number of solutions
    return countSolutions(queens, n, 0);
}

int main() {
    for (int i = 1; i <= 12; i++) {
        cout << i << ": " << nQueens(i) << endl;
    }
    return 0;
}
