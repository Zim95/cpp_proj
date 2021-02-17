/*
    You are given two integers, n and k. You need to find a value of x,
    such that, n! % k^x = 0.

    This means, n! is completely divisible by k^x.

    So we need to find all divisors of n!.

    But wait, here's a solution.

    Solution:
    -----------
    say n=5 and k= 2
    n!/k^x = 5!/2^x = (5 * 4 * 3 * 2 * 1)/2^x = (5 * 3 * 1 * 2^3)/2^x
    For the modulus to be 0, the denominator should completely divide the numerator,
    In the above case, 2^x will completely divide the numerator if x = 3.
    Because then, we have,
    (5 * 3 * 1 * 2^3)/2^3 = 5 * 3 * 1
    The denominator becomes 1 and the numerator is completely divided. 
*/
#include<iostream>

using namespace std;

int main() {
    return 0;
}