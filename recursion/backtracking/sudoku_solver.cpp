/*
    SUDOKU SOLVER:
    ================
    This problem requires no explanation because I already know how to play the game.
*/
#include<iostream>
#include<cmath>

using namespace std;

bool canPlace(int board[][9], int i, int j, int n, int k) {
    // Row and column check
    for(int x=0; x<n; x++) {
        if(board[x][j]==k || board[i][x]==k) {
            return false;
        }
    }

    // Grid check
    // If NxN is the matrix size: root(n) x root(n) is the grid size.
    int rn = sqrt(n);
    // subgrid starting coordinates
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    // iterate through the subgrid
    for(int x=sx; x<sx+rn; x++) {
        for(int y=sy; y<sy+rn; y++) {
            if(board[x][y] == k) {
                return false;
            }
        }
    }
    // If you made it here. You can place the number.
    return true;
}

bool sudokuSolver(int board[][9], int i, int j, int n) {
    // Base case
    if(i==n) {
        for(int a=0; a<n; a++) {
            for(int b=0; b<n; b++) {
                cout << board[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // row end: Go to next row, reset col
    if(j==n) {
        return sudokuSolver(board, i+1, 0, n);
    }
    // Skip pre-filled cells
    if(board[i][j]!=0){
        return sudokuSolver(board, i, j+1, n);
    }
    // Recursive case: fill the cell with all possible numbers.
    for(int k=1; k<=9; k++) {
        if(canPlace(board, i, j, n, k)) {
            // Assume
            board[i][j] = k;
            bool wasSolved = sudokuSolver(board, i, j+1, n);
            if(wasSolved) {
                return true;
            }
        }
    }
    // Backtracking
    board[i][j] = 0;
    return false;
}
int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudokuSolver(board, 0, 0, 9);
    return 0;
}