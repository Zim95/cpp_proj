/*
    Prime factors of a number
    -------------------------
    1. Naive approach
    2. Optimised approach
    3. Seive based approach
*/
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int> optimised_approach(int n) {
    // here we go upto root of n instead of the entire thing
    vector<int> prime_factors;
    for(int i=2; i<=sqrt(n); i++) {
        // The loop only goes till 3, because n becomes 1 when i becomes 3. And our loop has n in it.
        // Meaning the looping condition is not linear but gets divided per loop.
        if(n%i==0) {
            // reduce until not divisible by i
            while(n%i==0) {
                n = n/i;
            }
            prime_factors.push_back(i);
        }
    }
    // if n is not 1 by the end, then whatever remains is
    // considered prime number.
    // This is because our i<=sqrt(n) will hold negative way
    // before we reach the final value and that value will never get reached.
    // Therefore whatever remains is considered prime factor
    if(n!=1) {
        prime_factors.push_back(n);
    }
    return prime_factors;
}

vector<int> naive_approach(int n) {
    vector<int> prime_factors;
    for(int i=2; i<=n; i++) {
        // The loop only goes till 3, because n becomes 1 when i becomes 3. And our loop has n in it.
        // Meaning the looping condition is not linear but gets divided per loop.
        if(n%i==0) {
            // reduce until not divisible by i
            while(n%i==0) {
                n = n/i;
            }
            prime_factors.push_back(i);
        }
    }
    return prime_factors;
}

int main() {
    int n = 12;
    // Naive approach
    cout << "Naive approach" << endl;
    vector<int> prime_factors = naive_approach(n);
    for(int x: prime_factors) {
        cout << x << " ";
    }
    cout << endl;
    // Optimised approach
    cout << "Optimised approach" << endl;
    vector<int> prime_factors_optimsed = optimised_approach(n);
    for(int x: prime_factors_optimsed) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}