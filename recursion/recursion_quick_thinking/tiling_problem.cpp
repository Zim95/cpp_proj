/*
Question:
----------
Given, 
1. a wall of size 4 X N (4 rows, N columns).
2. tiles: either (1, 4) or (4, 1).
    either occupying 1 row and four columns: horizontal alignment.
    either occupying 4 rows and one column: vertical alignment.
In how many ways can you build the wall.

Answer:
--------
This is a long explanation:

If you use (1, 4) tile, That is if you place it flat.
    1. Then the number of columns decreases by 4.
        So now we need to solve the rest of n-4 recursively.
    
    2. From bottom to top, we have a height of 3 available.
        This means we cannot place (4, 1) tile, since it takes up height of 4 and only 3 is available.
        This mens we have to stack up 3 more (1, 4) tiles so that we end up with 4*(1, 4) tiles.
        This takes up four columns completely.

If you use (4, 1) tile, that is if you place it vertically.
    1. Then the number of columns decreases by 1.
        So now we need to solve the rest of n-1 recursively.

So the function is f(n) = f(n-1) + f(n-4)
Base case:
1. If the wall has a length of 1. There is only 1 way, place 1 tile vertical.
2. If the wall has a length of 2. There is only 1 way, place 2 tiles vertically.
3. If the wall has a length of 3. There is only 1 way, place 3 tiles vertically.
4. If the wall has a length of 4. Two ways, 4 vertically or 4 horizontally. 2 ways.
5. Anything greater than this can be calculated.

So upto 3 we can simply return 1.

Special case:
1. length 0. return 1 way.
*/

#include<iostream>

using namespace std;

int number_of_ways(int length) {
    if(length <= 3) {
        return 1;
    }
    return (number_of_ways(length-1) + number_of_ways(length-4));
}

int main() {
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i=0; i<10; i++) {
        cout << length[i] << " : " << number_of_ways(length[i]) << endl;
    }
    return 0;
}