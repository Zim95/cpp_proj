// Basic Bitmasking - Part 2
#include <iostream>

using namespace std;

int clearBitAt(int n, int i) {
    /*
        Create bitmask = (1<<i)
        Flip all bits of bitmask = ~(bitmask)
        Perform AND with n = (flipped_bitmask&n);
    */
    int bitmask = (1<<i);
    int flipped_bitmask = ~(bitmask);
    int result = (flipped_bitmask&n);
    return result;
}

int updateBitAt(int n, int i, int v) {
    /*
        Rules:
            to set:
            -------
            if 0 -> OR with 1
            if 1 -> OR with 1
            Sol: bitmask = 1 << i, operation = OR

            to clear:
            -------
            if 0 -> AMD with 0
            if 1 -> AND with 0
            Sol: bitmask = ~(i<<i), operation = AND

            to update:
            -----------
            the question is to either clear or set
            So we do both

            First we clear the bit.
            bitmask = ~(1 << i)
            operation = AND

            Now the bit has become 0
            if we want it to stay 0 -> OR with 0
            If we want it to become 1 -> OR with 1
            
            If our set value is 1, final_bit_mask = 0000100, operation OR
            If our set value is 0, final_bit_mask = 0000000, operation OR

            So the final bit mas = (v << i)
            if value is 1, we do 1<<i
            If value is 0, we do 0<<i
    */
    
    // first clear
    int init_bit_mask = ~(1<<i);
    int cleared_n = (n&init_bit_mask);

    // now set based on value
    int final_bit_mask = (v<<i);
    int setn = (cleared_n|final_bit_mask);

    return setn;
}


int main() {
    // Clear bit at ith position
    int a = 5;
    cout << "5 clear bit 2:=>(00000101&(~(00000001<<2))):=>(00000101&(~(00000100))):=>(00000101&11111011):=>(00000001) = " << clearBitAt(a, 2) << endl;
    cout << "5 clear bit 3:=>(00000101&(~(00000001<<3))):=>(00000101&(~(00001000))):=>(00000101&11110111):=>(00000101) = " << clearBitAt(a, 3) << endl;

    // Update bit at ith position with value v
    cout << "5 set bit 2 to 0:=>[(00000101&(~(00000001<<2)))|(00000000<<2)]:=>[(00000101&11111011)|(00000000)]:=>(00000001)|(00000000):=>(00000001) = " << updateBitAt(a, 2, 0) << endl;
    cout << "5 set bit 2 to 1(Unchanged):=>[(00000101&(~(00000001<<2)))|(00000001<<2)]:=>[(00000101&11111011)|(00000100)]:=>(00000001)|(00000100):=>(00000101) = " << updateBitAt(a, 2, 1) << endl;

    cout << "5 set bit 3 to 0 (Unchanged):=>[(00000101&(~(00000000<<3)))|(00000000<<3)]:=>[(00000101&11110111)|(00000000)]:=>(00000101)|(00000000):=>(00000101) = " << updateBitAt(a, 3, 0) << endl;
    cout << "5 set bit 3 to 1 (Unchanged):=>[(00000101&(~(00000001<<3)))|(00000001<<3)]:=>[(00000101&11110111)|(00001000)]:=>(00000101)|(00001000):=>(00001101) = " << updateBitAt(a, 3, 1) << endl;
    return 0;
}
