// Basic Bitmasking - Part 1
#include <iostream>

using namespace std;

bool isOdd(int n) {
    /*
        Odd even rule:
        --------------
        To find if a number is odd or even.
        Instead of using %2, just do a bitwise AND
        If result = 1 => Odd
        If result = 0 => Even
    */
    return n&1;
}

int getBitAt(int n, int i) {
    /*
        Return the ith bit of any given integer.
        Counting Right to Left, starting from 0.
        E.g.:
        n = 5 = 00000101
        i = ?
        In our example, if i = 2, the second bit of 5 is 1
        00000101 -> 5
        00000100 -> Bit mask
        AND--------
        00000100 -> This result is greater than 0 means the 2nd bit was 1.

        If i=3, the third bit of 5 is 0.
        00000101 -> 5
        00001000 -> Bit mask
        AND---------
        00000000 -> This result is 0 means the 3rd bit was 0.

        But how do we generate the bit mask?
         - Do (1 << i).
         - If we need second bit, our mask should be 00000001 << 2 = 00000100
         - If we need third bit, our mask should be 00000001 << 3 = 00001000
         - And so on..
    */
    int bit_mask = (1<<i);
    int bit = ((bit_mask&n)>0)?1:0;
    return bit;
}

int setBitAt(int n, int i) {
    /*
        Set the ith bit to 1.
        Counting Right to Left, starting from 0.
        E.g.:
        n = 5 = 00000101
        i = ?
        In our example, if i = 2, the second bit of 5 is 1
        00000101 -> 5
        00000100 -> Bit mask
        OR--------
        00000101 -> The bit was already 1 and remains unchanged.

        If i=3, the third bit of 5 is 0.
        00000101 -> 5
        00001000 -> Bit mask
        OR---------
        00001101 -> The bit was 0 and has been set to 1.

        But how do we generate the bit mask?
         - Do (1 << i).
         - If we need second bit, our mask should be 00000001 << 2 = 00000100
         - If we need third bit, our mask should be 00000001 << 3 = 00001000
         - And so on..
    */
    // For some reason this compiler return result - 1 and we need to add 1 to get the number. 
    int bit_mask = (1<<i);
    int result = (n|bit_mask);
    return result;
}

int main() {
    int a = 4;
    int b = 5;
    // odd even rule
    cout << "a is " << (isOdd(a)?"odd":"even") << endl;
    cout << "b is " << (isOdd(b)?"odd":"even") << endl;

    // get bit at i rule
    cout << "2 bit of 4 (100) is: " << getBitAt(a, 2) << endl;

    // set bit at i rule
    cout << setBitAt(a, 1) << endl;
    cout << "5 set bit 2:=>(00000101|(00000001<<2)):=>(00000101|00000100):=>(00000101):=>5 = " << setBitAt(a, 2) << endl;
    cout << "5 set bit 3:=>(00000101|(00000001<<3)):=>(00000101|00001000):=>(00001101):=>13 = " << setBitAt(a, 3) << endl;

    return 0;
}