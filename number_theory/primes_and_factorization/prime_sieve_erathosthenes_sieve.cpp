/*
    Prime numbers:
    --------------
    -> Cannot be divided by any number except itself and 1.
    
    Brute force:
    ------------
    Have a loop that runs from 2 to N-1 and check if any number divides it.
    If not its prime else its not prime.
    Time complexity - O(N)

    Sqrt:
    -----
    Say you want to see if 20 is a prime number. Lets look at all the factors.
    1 x 20 = 20
    2 x 10 = 20
    4 x 5 = 20
    ----------------> this is where things start to flip
    5 x 4 = 20
    10 x 2 = 20
    20 x 1 = 20

    So you see somewhere in the square root of 20, the multipliers
    start to become the same.

    This means we need not check for every number from 2 to N-1.
    We can simply check from 2 to sqrt(N) to see if a number is prime or not.

    Time complexity - O(sqrt(N))

    Seive:
    ------
    Seive of eratosthenes is the most popular prime finding algorithm.
    list = [True] * N
    list[0] = False
    list[1] = False
    index=2
    while index != N:
        if list[index] == True:
            for i in range(2, N):
                if (index*i) < N:
                    list[index * i] = False
                else:
                    break
        index += 1
    
    Each number sets all of its multiples to False.
    This loop is for that:
        for i in range(2, N)
    Here index=2, i = 2, 3, 4, 5, ... N
    So 2*2 = 4, 2*3 = 6 and so on, will be set to false.
    However, index * i may be greater than N.
    This means we may be out of index and get indexoutofrange errors.
    So we need to make sure index * i is within bounds by adding an if case.

    Optimization 1:
    ---------------
    In seive we need not start i from 2.
    Instead we can directly start it from i*i.
    i.e. a square.
    Why? You ask.
    You see we know that if a number is not prime, we will find its factor
    before its square root.
    So say we are processing 5. Then we can start from 25 directly.
    Because all numbers before 25 will already have a factor before we reach 5.

    So we can start from the square. So our loop will be.
        for i in range(index, N)
    So index=5, i=5, 6, 7, 8, 9, and so on
        5*5 = 25, 5*6= 30 and so on.
    Just a minor optimisation.

    Final optimisation:
    -------------------
    IGNORE ALL EVEN NUMBERS BECAUSE THEY ARE ALL DIVIDED BY 2.

    The time complexity for all this is
    => N/2 + N/3 + N/5 + N/7 ....
    => N(1/2 + 1/3 + 1/5 + 1/7 ....)
    The guy didnt prove it but the final complexity is.
    => O(N * log(logN))

*/
#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

// Naive approach
bool isPrime(int n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(int i=2; i<n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Sqrt approach
bool isPrimeSqrt(int n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(int i=2; i<=sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_sieve(int *p) {
    // mark all odd numbers as true
    for(int i=3; i<=1000000; i+=2) {
        p[i] = 1;
    }

    // now the sieve
    // we no longer need to start from 2,
    // because 2 is an even number and we are only going for odd.
    // odd iteration means 3 to N by a step of 2.
    for(ll i=3; i<=1000000; i+=2) {
        // if the index is not 1, meaning its already turned to 0 then continue.
        if (p[i]==1) {
            // here we have the even skip part down.
            // now we go with the multiple loop.
            // we start from the square.
            for(ll j=i*i; j<=1000000; j=j+i) {
                // j = square of i
                // j += j*i -> go to the next multiple
                p[j] = 0;
            }
        }
    }
}

int main() {
    int a = 7;
    int b = 8;
    // Naive approach
    cout << "Naive approach" << endl; 
    cout << a << ": " << isPrime(a) << endl;
    cout << b << ": " << isPrime(b) << endl;
    // Sqrt approach
    cout << "Sqrt approach" << endl;
    cout << a << ": " << isPrimeSqrt(a) << endl;
    cout << b << ": " << isPrimeSqrt(b) << endl;
    // Seive approach
    cout << "Seive approach" << endl;
    // construct the prime array
    int p[1000005] = {0};
    prime_sieve(p);
    p[0] = false;
    p[1] = false;
    p[2] = true;
    // now query
    for(int i=0; i<100; i++) {
        cout << i << ": " << (p[i]?"prime":"not prime") << endl;
    }
    return 0;
}