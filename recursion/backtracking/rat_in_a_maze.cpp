/*
Rat in a maze:
==============
We have an MXN matrix with some of the cells blocked.
We need to:
1. Find path from src to dest - Later
2. Count no of paths from src to dest - Later
3. Print all paths

Theory:
=======
- We need to move the rat from (0, 0) to (m-1, n-1).
- We have two options: down or right.
    -> if down is picked: call the same function by increasing i.
    -> if right is picked: call the same function by increasing j.
*/
#include<iostream>

using namespace std;

void print_matrix(int matrix[4][4], int m, int n) {
    for(int p=0; p<m; p++) {
        for(int q=0; q<n; q++) {
            cout << matrix[p][q] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_path(char maze[10][10], int soln[4][4], int i, int j, int m, int n) {
    // Base case
    if(i==m-1 && j==n-1) {
        soln[i][j] = 1;
        // print soln
        print_matrix(soln, m, n);
        return true;
    }
    // rat should be inside grid
    if(i>m||j>n) {
        return false;
    }
    // if current location is X return false
    if(maze[i][j] == 'X') {
        return false;
    }
    // So we mark the current location as 1
    soln[i][j] = 1;
    // Lets see if the path exists for right
    bool rightResult = is_path(maze, soln, i, j+1, m, n);
    // Lets see if the path exists for down
    bool leftResult = is_path(maze, soln, i+1, j, m, n);
    // Now we can change the soln back to 0 for the next path.
    soln[i][j] = 0;
    // if both results are true then return true. Else return false.
    if(rightResult&&leftResult){
        return true;
    }
    return false;
}

int main() {
    char maze[10][10] = {
        "0000",
        "0X00",
        "00X0",
        "0000"
    };

    int soln[4][4];
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            soln[i][j] = (maze[i][j]=='X')?-1:0;
        }
    }
    bool result = is_path(maze, soln, 0, 0, 4, 4);

    if(!result){
        cout << "Path does not exist" << endl;
    }

    return 0;
}