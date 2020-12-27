/*
    It's here finally. TOWER OF HANOI.
    Look up the problem definition and solution any where in the internet.
    It's there.

    The following code is the solution to the problem.

    Take example of 3 discs, move from A to C with B as helper.
    1. Move discs n-1: A -> B.
    2. Move disc n: A -> C. - This is the print operation.
    3. Move discs m-1: B->C.

    THIS IS THE GOLDEN ALGORITHM.
*/
#include<iostream>

using namespace std;

void move(int n, char src, char helper, char dest) {
    if(n==0) {
        return;
    }
    move(n-1, src, dest ,helper);
    cout << "Shift disc " << n << " from " << src << " to " << dest << endl; 
    move(n-1, helper, src, dest);
};

int main() {
    int n;
    cin>>n;
    move(n, 'A', 'B', 'C');
    return 0;
}
