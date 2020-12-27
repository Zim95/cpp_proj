/*
    Question:
    =========
    Count binary strings of length N, which have no consecutive ones?

    Answer:
    =======
    So the problem says, count all binary strings that have no consecutive ones.

    Suppose N=3.
    000
    001
    010
    011 - Consecutive one
    100
    101
    110 - Consecutive one
    111 - Consecutive one
    ----
    3 consecutive one binary strings.
    So total binary strings with no consecutive ones - (8-3) = 5.

    In case of 2,
    00
    01
    10
    11 - Consecutive ones
    ---
    1 consecutive one binary string.
    So total binary stings with no consecutive ones = 3

    In case of 1
    0
    1
    --     
    2 possibilies as there is only one digit and two possible values.

    In case of 0
    we have 0
    which is 1 possibility.

    You can see that, f(n) = f(n-1) + f(n-2)
    Because, f(3) = f(2) + f(1), i.e. 5 = 3 + 2

    Valid strings: Strings with no consecutive ones
    Invalid strings: Strings with consecutive ones

    How to think:
    ===============
    if the first bit is 0, the number od valid strings for the remaining can be given by f(n-1).
    if the first bit is 1,
        the last bit of the valid string for n-1, has to be 0.
        this means we have run out of options for the second last bit as well.
        if the last bit is 0, the second last bit has to be 1 otherwise it will be an invalid string.
    Therefore, we are left with (n-2) options.
    for, n-2 valid strings is given by f(n-2).

    How I came up with the base case?
    ----------------------------------
    I already knew from the video that the formula is f(n) = f(n-1) + f(n-2)
    I took the case of n=3
    so f(3) = f(2) + f(1)
    I already counted f(3) -> 5 and f(2) -> 3,
    So, 5 = 3 + x, x=2
    So I knew the value of f(1) should be 2 for the recursion to hold.
    I did the same thing with f(2) = f(1) + f(0)
    I got the value of f(0) to be 1.
*/

#include<iostream>

using namespace std;

int count_valid_strings(int n){
    if(n==0) {
        return 1;
    }
    if(n==1) {
        return 2;
    }
    return count_valid_strings(n-1) + count_valid_strings(n-2);
}

int main() {
    int n=4;
    cout << count_valid_strings(n) << endl; // if n is 4 output is 8
    return 0;
}