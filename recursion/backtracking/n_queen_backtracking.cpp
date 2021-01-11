/*
N-Queen problem
================
In a NxN matrix. PLace N queens such that all queens are safe and no queen
cuts each other.

Few properties:
---------------
1. There can be only one queen per row. (Obvious).
2. There can be only one queen per column. (Obvious).

So the matrix reduces to sub matrices.

Once a queen is placed. We need to omit the row, the column and the diagonals.

Solution steps:
----------------
Take 4x4 matrix.

Place one queen in (0,0).

Now we know that,
- In the second row,
    we cannot place queen on: (1, 0) and (1, 1).
    However we can place it on (1, 2) and (1, 3).

    And so on.

So placing a queen has an impact on the entire board.
So, we need to have a check function that checks if we can place a queen or not.

In our solution, we will recursively call function for downward rows, meaning
WE ONLY HAVE TO CHECK FOR SAFETY FOR ROWS ABOVE THE CURRENT ROW.
We need to check if there is a queen:
    - on the same column.
    - on left diagonal.
    - on right diagonal.

So lets start.
*/
#include<iostream>

using namespace std;

void printMatrix(int matrix[][10], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[][10], int i, int j, int n) {
    // 1. CHECK FOR COLUMN
    // Stay on the same column. Go upto the row becomes 0.
    for(int row=i; row>=0; row--){
        if(board[row][j] == 1) {
            return false;
        }
    }

    int x, y;
    // 2. CHECK FOR LEFT DIAGONAL
    x = i;
    y = j;
    while(x>=0 && y>=0) {
        if(board[x][y]==1) {
            return false;
        }
        x--;
        y--;
    }

    // 3. CHECK FOR RIGHT DIAGONAL
    x = i;
    y = j;
    while(x>=0 && y<n) {
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    // Making it here means its safe so return true.
    return true;
}

bool solveNQueen(int board[][10], int i, int n) {
    // base case
    if(i==n) {
        // this means that we have placed all queens from row (0,...n-1).
        // print
        printMatrix(board, n);
        // do not return true because, if we return true, our for loop stops and other cases wont be printed.
        // so even if the path has been explored return false.
        return false;
    }
    // place queen on each column for the row i.
    for(int j=0; j<n; j++) {
        // put a queen if safe.
        if(isSafe(board, i, j, n)) {
            // set the queen on the board.
            board[i][j] = 1;

            // call recursively. If you can place a queen on the next row then good. return true.
            // this part is a bit confusing. As we could have simply done a recursive call.
            // the recursive call will return a false if the current position is not valid.
            // so we need to check.
            // This is because, if you placed the queen at the wrong place the other queens cannot be placed.
            bool canPlaceQueen = solveNQueen(board, i+1, n);
            if(canPlaceQueen) {
                return true;
            }

            // remove queen to put it on the next place. Reset for next position.
            board[i][j] = 0;
        }
    }
    return false;
}


int main() {
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board, 0, n);
    return 0;
}