/*
    We all know that the range of our arrays are 10^7.
    i.e. our max array size can be 10000000.
    What if the number we are checking for prime is 10^10.
    Then what do we do?

    If the number is <= 10^7, we return true or false by looking at
    our seives array.
    Otherwise, we will get the square root of that number.
    Square root of the number 10^10 = 10^5, which is less than 10^7.
    However, we are not just returning the value fo 10^5.
    We have to iterate through each number less than 10^5,
    i.e. use the squre root method.

    But wouldnt that be unoptimal, if we get a TLE for the square root
    method even for smaller numbers,
    how would this work for 10^5.
    Well we are not iterating through each and every number but only primes.

    Meaning, we will iterate through primes list until the square root of 10^10.
*/
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
#include<cmath>
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

bool isPrime(bitset<10000005> &b, vector<int> &v, int n, ll no) {
    // if the number is less than 10^7, just query and return true or false
    if(no<=n) {
        return b[no]?true:false;
    }
    // Otherwise, iterate through primes list until the square root is found.
    for(int i=0; v[i]<sqrt(no); i++) {
        if((no % v[i]) == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    const int n = 10000005;
    bitset<10000005> b; // bitset array for seive
    vector<int> v; // vector to store all primes
    prime_seive(b, v, n);
    ll check = 2147483547;
    cout << isPrime(b, v, n, check) << endl;
    return 0;
}