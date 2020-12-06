// Basic bitmasking - Part 3
#include<iostream>

using namespace std;

int clearLastIBits(int n, int i) {
    /*
        Clear last 3 bits of 13
        00001101 -> 13
        11111000 -> Bitmask
        AND--------
        00001000 -> 8
    */
    int bitmask = (-1<<i);
    return (n&bitmask);
}

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

int main() {
    int n = 13;
    cout << "Clear last 3 bits of 13 = "<< clearLastIBits(n, 3) << endl;

    int k = 118;
    cout << "Clear bit from 2 to 7 of 118 = " << clearBitsFromItoJ(k, 2, 7) << endl;
    return 0;
}