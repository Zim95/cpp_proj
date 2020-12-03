/*
We will understand some basic concepts of bit manipulation

Number representation:
AND - Both bits need to be 1
OR - Any one bit needs to be 1
NOT - Returns 0 if 1 and 1 if 0
XOR - Only 1 bit can be one

Operators:
Bitwise AND -> &
Bitwise OR -> |
Bitwise NOT -> ~
Bitwise XOR -> ^
*/
#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 4;

    // AND, OR, NOT
    cout << "The precedence of & and | operator is from left to right" << endl;
    cout << "(5 & 4):=> (101 & 100):=> (100) = " << (a & b) << endl; // 4
    cout << "(5 | 4):=> (101 | 100):=> (100) = " << (a | b) << endl; // 5
    
    // NOT
    a = ~a;
    cout << "Not 5:" << a << endl; // -6
    /*
    Explanation:
    1. We have 8 bits, so 5 = 00000101
    2. NOT of this is = 11111010
    3. Therefore, our result is such a high negative number
    */

    // XOR properties
    // 1. a ^ a = 0
    cout << ">>>>>>>>>>>>>>>> XOR <<<<<<<<<<<<<<<<<" << endl;
    cout << "XOR with same number is 0" << endl;
    cout << "(5 ^ 5):=>(0) = " << (a^a) << endl;
    // 2. a ^ b ^ a = b
    cout << "Can be used to cancel even occurences of numbers" << endl;
    cout << "(5 ^ 4 ^ 5):=>(4)= " << (a^b^a) << endl;

    // Shift operators
    cout << ">>>>>>>>>>>>>>>>>>>> SHIFT OPERATORS <<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "1. Left shift: Remove, MSB and insert 0 at end:" << endl;
    cout << "(5<<1):=>(00000101<<1):=>(00001010):=>(10) = " << (5<<1) << endl;
    cout << "Left shift means multiply by 2. But do not add spaces in between like (a << 1)." << endl;
    cout << "Keep them together like (a<<1)" << endl;
    cout << "Therefore we can say that: a<<b = a * (2**b)" << endl;
    cout << endl;
    cout << "2. Right shift: Remove, LSB and insert 0 at the beginning:" << endl;
    cout << "(5>>1):=>(00000101>>1):=>(00000010):=>(2) = " << (5>>1) << endl;
    cout << "Right shift means divide by 2. But do not add spaces in between like (a >> 1)." << endl;
    cout << "Keep them together like (a>>1)" << endl;
    cout << "Both shift operators do not work well with variables. Need to see it through"<<endl;
    cout << "Therefore we can say that: a>>b = a * (2**(-b))" << endl;

    return 0;
}