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

    Lets try and deduce this mathematically,
    we can say that,
    k = (p1 ^ k1) * (p2 ^ k2) * (p3 ^ k3) * (p4 ^ k4) * ....
    For eg:
    if k = 24, we can say
    k = 2 * 2 * 2 * 3
      = (2^3) * (3^1)
    
    Now,
    We need to count the occurence of each one of p1, p2 and so on in n!.

    E.g.
    To count the occurence of 5 in 100!.
    We need to do:
    100/5 + 100/5^2 + 100/5^3

    Now, 100/5^3 = 100/125 = 0, so the chain will end here.
    So, we are left with,
    100/5 + 100/25 = 20 + 4 = 24
    There are 24 occurences of 5s in 100!

    We can prove this,
    100! = 100 * 99 * 98 * ... 95 * ... 90 * ... 85 and so on.
    There are 24 occurences of 5.
    For eg:
    5 contains one 5
    10 contains one 5
    15 contains one 5
    20 contains one 5
    25 contains two 5s
    30 contains two 5s
    and so on,....
    Total there are 24, 5s

    So similarly if we want to find the number of occurences in n!,
    n/p + n/p^2 + .... until 0.

    So lets say the occurences of primes, p1, p2, p3, p4... pl in n!,
    Or better yet, the count of primes, p1, p2, p3, p4... pl in n!,
    is, C1, C2, C3 and so on.

    So we have some form of pattern such as,
    n!/k = (p1^c1 * p2 ^c2 ,...,pn^cn * some numbers we dont care about) / (p1^k1 * p2^k2, .....)
    So,
    n!/k^x = (p1^c1 * p2 ^c2 ,...,pn^cn * some numbers we dont care about) / (p1^(k1*x) * p2^(k2 * x), .....)

    Here,
    k1 * x <= c1, since we want to cancel the denominator completely,
                    the value c1 which is the power of the numerator
                    should be atleast greater than or equal to k1x, which
                    is the power of the denominator.
    k2 * x <= c2, and so on...

    From this we can conculde that,
    x <= c1/k1
    x <= c2/k2
    ...
    x <= cn/kn

    So x = min(c1/k1, c2/k2, ... cn/kn)

    Here,
    k1, k2 and so on, will be identified by the prime factorization of k.
    And,
    c1, c2 and so on, will be identified by the above formula to get the
    occurences of numbers within a factorial.

    Once we know these values,
    we can just find the minimum of c1/k1, c2/k2 and so on,....
    That will be our x.

    REMARKS
    ==========
    FUCK, this was disgustingly hard to understand. I still dont understand it.
    Its like maths in high school.
    We need to find a way to get good at this shit no matter what.
    I understood the steps somehow, but how do I think of such a soln in
    the coming future?

    So what are the steps:
    1. Find the prime factors of k. this gives us: p1 ^ k1, p2^k2, and so on.
    2. Find the occurences of each prime on the numerator: these will give us, c1, c2 and so on.
    3. Using this, we can get the minimum of the division operation.
*/
#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        int ans = INT_MAX;

        // here we will iterate through each and every number
        // and check divisibility rather than just iterating through
        // prime numbers.
        // Because for prime, we will need to first use sieve and get the
        // prime array.
        // We will not get the prime array, rather we will iterate through each
        // number starting from 2.
        for(int i=2; i<sqrt(k); i++) {
            // all prime factors will be identified before sqrt of k.
            if(k % i != 0) {
                continue;
            }
            int power_of_prime = 0;
            while(k % i == 0) {
                k = k/i;
                power_of_prime++;
            }

            // now lets find out the occurences of i in n!.
            // formula = n/i + n/i^2 + n/i^3 + .... until 0.
            int occ = 0;
            int divisor = i;
            while(n/divisor != 0) {
                occ += (n/divisor);
                divisor = divisor * i;
            }

            // the occurences of prime in n! is c1, i.e. occ is c1
            // the power of prime is k1, so we get x.
            ans = min(ans, (occ / power_of_prime));
        }

        // we also know that,
        // the remaining number is a prime factor on its own.
        // with the power od 1.
        if (k>1) {
            int p = 1; // the power of k is 1.
            int occ = 0;
            int divisor = k; // because k is a prime factor on its own.
            while(n/divisor != 0) {
                occ += (n/divisor);
                divisor = divisor * k;
            }
            ans = min(ans, (occ / p));
        }

        if(ans == INT_MAX) {
            // if nothing changed.
            // if n! does not contain all prime factors of k.
            // we simply output 0 in that case.
            ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}

// TODO: Change the type of divisor to long long, because it will result in big numbers.
