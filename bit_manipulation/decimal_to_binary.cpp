#include<iostream>

using namespace std;

int convertDecimalToBinary(int n){
    /*
        13 = 1101

        ans = 0

        (last bit)1 * 1 = 1; right shift;
        (last bit)0 * 10 = 0; right sift;
        (last bit)1 * 100 = 100; right shift;
        (last bit)1 * 1000 = 1000; right shift;

        all zeroes - terminate

        result = 1000 + 100 + 0 + 1 = 1101 = 13

    */
    int binary = 0;
    int power = 1;
    while(n) {
        int last_bit = (n&1);
        binary += (last_bit * power);
        power *= 10;
        n = (n>>1);
    }
    return binary;
}

int main() {
    cout << "0 = " << convertDecimalToBinary(0) << endl;
    cout << "2 = " << convertDecimalToBinary(2) << endl;
    cout << "5 = " << convertDecimalToBinary(5) << endl;
    cout << "7 = " << convertDecimalToBinary(7) << endl;
    cout << "9 = " << convertDecimalToBinary(9) << endl;
    cout << "11 = " << convertDecimalToBinary(13) << endl;
    return 0;
}