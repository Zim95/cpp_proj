/*
    Almost prime (Codeforces)
    -------------------------
    Almost prime numbers are those that have exactly two prime divisors.
    Not itself and not 1. Exactly two prime divisors.
    The questions wants us to get a count of almost prime numbers
    between range: 1-n.

    How to do it,
    While creating the seive, we unset the indexes of all multiples right?
    So now while unsetting, also add 1 to another array.
    See we are keeping track of how many times a number is divided.

    For eg: between 1 and 10.
    6 has two prime factors, 2 and 3.
    10 has two prime factors, 2 and 5.
    So there are two numbers 6 and 10 that are almost prime between 1 and 10.
*/
#include<iostream>

using namespace std;

void prime_seive(int *p, int *count_array) {
    // set 2. 0 and 1 are already unset
    p[2] = 1;
    // set all odd numbers
    for(int i=3; i<=1000000; i+=2) {
        p[i] = 1;
    }
    // now comes the seive part
    // however we will not skip any even numbers
    // because we need to know how many times those numbers have been divided as well.
    for(int i=2; i<=1000000; i++) {
        if(p[i]==1){
            for(int j=i; j<=1000000; j+=i) {
                p[j] = 0; // unsetting part
                count_array[j] += 1; // addition part.
            }
        }
    }
}

int main() {
    int p[1000005] = {0};
    int ca[1000005] = {0};
    prime_seive(p, ca);
    // check for range 1 and 10. We should get 6 and 10.
    for(int i=0; i<=10; i++) {
        if(ca[i] == 2) {
            cout << i << " ";
        }
    }
    return 0;
}