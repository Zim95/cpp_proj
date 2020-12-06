#include<iostream>

using namespace std;

int getLastBit(int n) {
    int lastbit = (n&1)>0?1:0;
    return lastbit;
}

int countBitsApproachA(int n) {
    /*
        sum = 0
        while n > 0:
            Get last bit (0th bit)
            if last bit is 1: sum+=1
            Right shift n
        
        Complexity:
        The loop goes on for k times: Until all bits are zeros.

        In any number(N), the maximum number of bits you can have is LogN + 1
        As in, in number 15 = The number of bits = 00001111 = 4 = int(log(15)) + 1

        So k = Log(N) + 1;
        So Time complexity = O(Log(N)) + 1
    */
    int sum = 0;
    while(n) {
        if(getLastBit(n)==1) {
            sum += 1;
        }
        n = (n>>1);
    }
    return sum;
}

int countBitsApproachB(int n) {
    /*
        Much faster than approach A:
        Removes last bit by doing: n&(n - 1)

        9 = 1001 -> add 1
        9 & 8 = (1001&1000) = 1000 -> add 1
        8 & 7 = (1000&0111) = 0000 -> add 1

        Total = 3
        Runs as many times as the number of 1s.

        Time complexity:
        Number of set bits: O(LogN)
        The complexity is the same because the number of iterations happens in the same order.
        But the number of iterations are reduced.
        Think of it like difference between looping through each item in the list and looping through
        only quarter of the items in the list and getting things done.
    */
    int sum=0;
    while(n) {
        n = (n&(n-1));
        sum++;
    }
    return sum;
}

int countBitsApproachC(int n) {
    // Use inbuilt function:
    return __builtin_popcount(n);
}

int main() {
    int n=13;
    cout << "Approach A = " << countBitsApproachA(n) << endl;
    cout << "Approach B = " << countBitsApproachB(n) << endl;
    cout << "Approach C = " << countBitsApproachC(n) << endl;
    return 0;
}