/*
    FAST MODULO EXPONENTIATION
    ==========================
    We need to compute:
    (a^b) % m
    The brute force approach is to multiply a, b times, which takes linear time.
    However,
    In this approach we will look at a method which will do it in,
    O(logb) time.

    Uses:
    - Bit masking
    - Recursion

    -> Refer fast exponentiation in bit manipulation section for more clarity.

    Solution:
    ----------
    a = 3
    b = 5
    => 3^5
    => 3 ^ (101)
    => 3 ^ (1 * 2^2 + 0 * 2^1 + 1*2^0)
    => 3 ^ (1 * 2^2) * 3 ^ (0 * 2^1)  * 3 ^ (1 * 2 ^ 0) [By using the rule: a^(b+c) = a^b * a^c]----(i)
    => (3 ^ 4) * (3 ^ 0) * (3 ^ 1)

    We will apply mod to each step.
    The multiplicative rule states that:
    (a*b)%m = [(a%m) * (b%m)] % m

    So, we will essentially have
    => [(3 ^ 4)%m * (3 ^ 0)%m * (3 ^ 1)%m]%m
*/
#include<iostream>
#define ll long long

using namespace std;

ll fastExp(ll a, ll b, ll m) {
    ll res = 1;
    while(b>0) {
        if(b&1>0) {
            res = (res * a)%m; // This is the outer mod m
        }
        a = (a*a)%m; // This is the inner mod m
        b = b>>1;
    }
    return res;
}

int main() {
    cout << fastExp(5, 3, 5) << endl;
    return 0;
}