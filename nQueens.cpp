/*
 * Name: Michael Elrod
 * Date Submitted: 11/15/2022
 * Lab Section: 001
 * Assignment Name: Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <vector>
#include <iostream>

using namespace std;

// Checks surrounding positions to see if a Queen can be placed
bool queenCanBePlaced(int** queens, int n, int col, int row)
{
    // Check the row
    for(int c=0;c<n;c++)
        if(queens[row][c] == 1)
            return false;

    // Check lower diagonal (left to right)
    for(int r=row,c=col;r>=0 and c>=0;r--,c--)
        if(queens[r][c] == 1)
            return false;

    // Check upper diagonal (left to right)
    for(int r=row,c=col;r<n and c>=0;r++,c--)
        if(queens[r][c] == 1)
            return false;

    return true;
}

int countSolutions(int** queens, int n, int col)
{
    int count = 0;

    if(n == col)
        return 1;

    for(int i=0;i<n;i++){
        int row = i;
        //Check for valid positions, then place the Queens
        if(queenCanBePlaced(queens, n, col, row)){
            // Place Queen
            queens[row][col] = 1;
            // Search again
            count += countSolutions(queens, n, col+1);
            queens[row][col] = 0;
        }
    }
    return count;
}

int nQueens(int n)
{
    // To pass a 2D array we use double indirection (int**)
    int** queens = new int *[n];

    // Make array 2D
    for(int i=0;i<n;i++){
        queens[i] = new int[n];

        // Fill spaces with '0'
        for(int j=0;j<n;j++)
            queens[i][j] = 0;
    }
    // Count the number of solutions
    return countSolutions(queens,n,0);
}

/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
*/