/*
    You are given one number n. You are to find three distinct
    integers, a, b and c, such that, 2<=a,b,c and a * b * c = n
    or say that it is impossible to do it.

    BTW, the value of n can go from 2 to 10^9. Meaning n should be long long.

    The idea of this problem is:
    If a number has atleast 3 prime factors, then the answer is YES.
    If not then the answer is NO.

    However, there is another case.
    Consider, 64 -> 2^6,
    From 2^6, we can get three separate numbers,
    2^1, 2^2 and 2^3, so this is a valid case.

    However, in case of 32 = 2^5,
    We can at max, get
    2^1, 2^2, So we dont get 3 numbers.

    So, if there is a single prime factor, the power of it should be >=6.

    If we have two prime factors,
    we can get the third by doing, c = n/(a*b)
    Which gives us the next number.
    If this number is not an integer then ofcourse, the answer is NO.
    Also, if the number c is same as either a or b, the answer is NO.
*/

// THIS SOLUTION IS INCOMPLETE: We have only added the first case
// THE OTHER CASES NEED TO BE ADDED, BUT WE WONT WASTE TIME HERE.
// WE WILL DO THIS LATER AFTER COMPLETING THE COURSE.
#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin>>n;
        // prime factor of n
        int count = 0;
        for(int i=2; i<sqrt(n); i++) {
            if(n%i != 0) {
                continue;
            }
            count++;
            while(n%i == 0) {
                n = n/i;
            }
        }
        if(n>1) {
            count += 1; // for the last prime factor.
        }
        if(count>0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}