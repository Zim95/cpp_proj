// Basic bitmasking - Part 5
#include<iostream>

using namespace std;

int clearBitsFromItoJ(int n, int i, int j) {
    /*
        Clear 3 to 7 (i to j)
        01110110 -> 118
        10000011 -> bitmask
        AND-----
        00000010 -> 2

        Bitmask
        - 11111111 -> -1
        - 10000000 -> (-1<<j)
        - 10000000 | 00000011 = 10000011-> ((-1<<j) | ~(-1<<(i-1)))
    */
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1<<i) - 1;
    int bitmask = (a|b);
    return (n&bitmask);
}

int replaceBitsInNByM(int n, int i, int j, int m) {
    /*
        Say,
        n = 15 -> 00001111
        i = 1, j = 3
        m = 2 -> 010
        Expected results: 00000101 -> 5
        
        Explanation
        - We have: 00001111
        - Clear bits from i to j: 00000001
        - Mask: Shift m<<i: 00000010 << 1 : 00000100
        - OR with mask: 00000001|00000100 : 00000101 -> 5
    */
    int n_ = clearBitsFromItoJ(n, i, j);
    int result = (n_|(m<<i));
    return result;
}

int main() {
    /*
        You are given two 32-bit numbers, N and M and two positions i and j.
        Write a function to set all bits between i and j in N equal to M.

        MEANING: insert M in N
    */
    int n=15;
    int i=1, j=3;
    int m=2;
    cout << "replaceBitsInNByM of 15 = " << replaceBitsInNByM(n, i, j, m) << endl;
    return 0;
}