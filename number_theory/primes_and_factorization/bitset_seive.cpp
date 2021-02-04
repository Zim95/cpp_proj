/*
    Bitset seive
    ------------
    Space optimized version of seive of eratosthenes.
    More space = More range of prime numbers you can store.

    We will be using a special class for this called the bitset class.
        bitset<100> b;
    If we have a boolean array, bool arr[10]
    This means the array's actual size is 80 bits.
    Each bool variable is 1 byte -> 8 bits. So the size is 80 bits.

    However, in bitset array, we can store each index with one bit.

    Now, we know that in seive of eratosthenes, the prime array that we create
    can be huge.
    But we dont really need to have actual true, false values.
    We can simply use bits 0 for false and 1 for true.
    And with that we will have optimized a lot of space.
    This is why its useful.
*/
#include<iostream>
#include<bitset>
#include<vector>
#define ll long long

using namespace std;

void prime_seive(bitset<10000005> &b, vector<int> &v, int n) {
    // set all the bits
    b.set();
    // unset all even numbers
    for(int i=2; i<=n; i+=2) {
        b[i] = 0;
    }
    // now for odd numbers
    for(ll i=3; i<=n; i+=2) {
        if(b[i]!=1) {
            continue;
        }
        v.push_back(i); // also push back the prime
        for(ll j=i*i; j<=n; j=j+i) {
            b[j] = 0;
        }
    }
}

int main() {
    const int n = 10000005;
    bitset<10000005> b; // bitset array for seive
    vector<int> v; // vector to store all primes
    prime_seive(b, v, n);
    // printing the first 100 primes.
    for(int i=0; i<100; i++) {
        cout << v[i] << " ";
    }
    return 0;
}