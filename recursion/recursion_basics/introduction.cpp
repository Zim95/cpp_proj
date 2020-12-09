/*
Recursion: 
When a function calls itself with a modified input. Simple.
E.g.
// Recursive program to count to 10.
int count_to_ten(int n) {
    // terminating condition
    if (n == 10) {
        cout << "10" << endl;
        return 0;
    }
    cout << n << endl;
    count_to_ten(n+1); // Function calls itself with modified input.
    return 0;
}

Parts of a Recursive Algorithm:
===============================
1. Base Case
2. Recursive Call

Sample problem 1: Getting factorials
*/
#include<iostream>

#define ll long long

using namespace std;

ll factorial(int n) {
    /*
    This method of factorial will not work for larger numbers.
    */
    if(n==0){
        return 1;
    }
    ll result = n*factorial(n-1);
    return result;
}


int main() {
    int n;
    cin>>n;
    cout << n << "! = " << factorial(n) << endl;
    return 0;
}