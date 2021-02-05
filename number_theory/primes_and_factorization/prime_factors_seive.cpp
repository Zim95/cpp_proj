/*
    Getting prime factors by using sieve of eratosthenes.
    -----------------------------------------------------
    1. Calculate primes vector by using sieve method.
    2. Divide by all primes less than the square root of n.

    Computing seive = O(NloglogN)
    Getting prime_factors = O(logN)
    Total time complexity = O(NloglogN) + O(logN)
*/
#include<iostream>
#include<vector>
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

vector<int> prime_factors(int n, vector<int> &primes) {
    vector<int> factors;
    for(int i=0; primes[i]<sqrt(n); i++) {
        if(n % primes[i] == 0) {
            factors.push_back(primes[i]);
            while(n%primes[i]==0) {
                n = n/primes[i];
            }
        }
    }
    if(n!=1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int p[1000005] = {0};
    vector<int> primes;
    sieve(p, primes);
    int n = 12;
    vector<int> factors = prime_factors(n, primes);
    for(int x: factors) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}