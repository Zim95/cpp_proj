/*
    How to count divisors:
    =============================
    You can do it the naive way,
    where you see if each number divides the number starting from 2
    and then if they do, they are divisors.

    Or, better:
        Calculate Prime factors:
        - Calculate seive and get primes array.
        - Go from first prime to square root of n.
        - Also count the power of each prime factor.
        - The answer will be the product of all powers of prime factors.

    E.g.
    Consider 60
    The prime factor of 60 => 2 x 3 x 5
    Because the prime factors we get is: 2 x 2 x 3 x 5
    And then our prime factors become 2^2 x 3^1 x 5^1

    Now what does we can get any divisor of 60 by using 2, 3 and 5
    We can use 2^0, 2^1 and 2^2, 3^0 and 3^1 And finally 5^0 and 5^1.
    This is because our prime factors, 2 has the power of 2, 3 has the power
    of 1 and 5 has the power of 1.
    So we can pick (2^0,1,2), (3^0,1) and (5^0,1)
    3 powers of 2, 2 powers of 3 and 5.
    
    So if we pick 2^0, 3^1 and 5^1, we get
    1 x 3 x 5 = 15, which is a divisor of 60

    Say we pick, 2^2, 3^0, 5^1
    4 x 1 x 5 = 20, which is also a divisor of 60

    Meaning a combination of these factors with their powers give us a divisors.

    There are
    3 powers of 2 meaning 3 unique numbers, i.e. 2^0, 2^1 and 2^2.
    2 powers of 3 meaning 2 unique numbers, i.e. 3^0 and 3^1.
    2 powers of 5 meaning 2 unique numbers, i.e. 5^0 and 5^1.

    So the number of divisors are, 3 x 2 x 2 = 12
    This is the formula.
*/
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#define ll long long

using namespace std;

void sieve(int *p, vector<int> &primes) {
    p[2] = 1;
    primes.push_back(2);
    for(int i=3; i<=1000000; i+=2) {
        p[i] = 1;
    }
    for(ll i=3; i<=1000000; i+=2) {
        if(p[i]==1) {
            primes.push_back(i);
            for(ll j=i*i; j<=1000000; j=j+i) {
                p[j] = 0;   
            }
        }
    }
}

int number_of_divisors(int n, vector<int> &primes) {
    map<int, int> m;
    for(int i=0; primes[i]<sqrt(n); i++) {
        int power_of_prime = 0;
        if(n % primes[i] == 0) {
            while(n%primes[i]==0) {
                power_of_prime++;
                n = n/primes[i];
            }
            m.insert(make_pair(primes[i], power_of_prime + 1)); // We put +1 to consider power of 0 as well.
        }
    }
    if(n!=1) {
        m.insert(make_pair(n, 2)); // power 0 and power 1
    }
    int number_of_divisors = 1;
    for(pair<int, int> x: m) {
        number_of_divisors *= x.second; // multiply the power of the prime
    }
    return number_of_divisors;
}

int main() {
    int p[1000005] = {0};
    vector<int> primes;
    sieve(p, primes);
    int n = 60;
    cout << "Total divisors of " << n << " is: " << number_of_divisors(n, primes) << endl;
    return 0;
}