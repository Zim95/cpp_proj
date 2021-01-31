/*
    Question:
    ----------
    You will have n queries.
    Each query has a range.
    You need to count the total number of prime numbers in that range.

    How to do it:
    -------------
    Create a seive array.
    For queries: Create a prefix sum array that counts the total of primes.
    Query will be: prefix_sum[a-1] - prefix_sum[b]
    Where, a b is the range in the query.
*/
#include<iostream>
#define ll long long

using namespace std;

void prime_sieve(int *p) {
    for(int i=3; i<=1000000; i+=2) {
        p[i] = 1;
    }
    for(ll i=3; i<=1000000; i+=2) {
        if(p[i] != 1) {
            continue;
        }
        for(ll j=i*i; j<1000000; j=j+i) {
            p[j] = 0;
        }
    }
    p[2] = true;
    p[0] = p[1] = false;
}

void prefix_sum(int *p, int *ps) {
    for(int i=1; i<1000000; i++) {
        ps[i] = ps[i-1] + p[i]; // if p[i] is 1 we add 1 else we add 0
    }
}

int main() {
    int p[1000005] = {0};
    int ps[1000005] = {0};
    // build the seive
    prime_sieve(p);
    // build seive prefix sum
    prefix_sum(p, ps);
    // query
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << "Total primes between " << a << " and " << b << ": " << (ps[b] - ps[a-1]) << endl;
    }
    return 0;
}