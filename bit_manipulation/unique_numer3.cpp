/*
We are given an array containg n numbers.
All the numbers are present thrice except for one number which
is only present once. Find the unique number.
Only use - bitwise operators, and no extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3
Sample Output
3
Explanation
3 is present only once
*/
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    /*
    Explanation:

    Here every number occurs 3 times except one.
    So module number = 3

    We cannot do a XOR here because XOR does not work for odd occurences.

    So we do this, and use column wise sum
    1 - 0 0 1
    1 - 0 0 1
    1 - 0 0 1
    2 - 0 1 0
    2 - 0 1 0
    2 - 0 1 0
    3 - 0 1 1
    ----------
        0 4 4
    % 3 each number
    ----------------
        0 1 1 - 3
    Thats how we do it.
    */

    int n;
    cin >> n;
    cin.get();

    // representation of bits
    int bits[64] = {0}; // 64 bit array filled with zeroes.

    // we will add to array while we read the input.
    while(n--){
        int no;
        cin>>no;

        // we need to extract each bit and add it to the position.
        int pos = 0;
        while(no>0) {
            int last_bit = (no&1);
            bits[63-pos] += last_bit; // the last bit is gets added to first position, So we are reversing it by doing 63-pos.
            pos++;
            no = (no>>1);
        }
    }

    // now do modulo 3
    // along with that keep adding 2 power in increasing order starting from reverse.
    // e.g. 1*(2^n) + ........ + 1*(2^2) + 1*(2^1) + 1*(2^0)
    int power = 0;
    for(int i=63; i>-1; i--) {
        bits[i] = (bits[i]%3) * (pow(2, power));
        power++;
    }

    // now we just need the sum
    int sum = 0;
    for(int x: bits){
        sum += x;
    }
    cout << sum;
    return 0;
}