/*
    Segmented seive:
    ================

    Problem:
    --------
    Consider a problem prime generator.

    The same problem that you couldnt solve on SPOJ and gave up
    competetive programming. Yes, that one.

    Its time to fuck that problem over with your new found powers.

    So, here is the problem:

    You will be given a range of numbers in queries,
    and you need to generate all prime numbers within that range.

    Solution Strategy:
    ------------------
    Well we can use seive for that right? Simply create the seive array
    and just print the numbers for each range in the query.
    WRONG
    The thing is the range of numbers can go upto 10^9.
    As we know the maximum range of our array is 10^7.

    So our seive array cannot be of the size 10^9.

    This is where we were fucked.

    This is why we could not create the sieve array at all and gave up
    on this problem.

    This was the first time we heard about seive of eratosthenes.

    However, we could not apply seive of eratosthenes because the seive array
    wouldnt get created.
    Well now we know why, the range exceeded the maximum range.

    So, we need to use segmented seive for this.
    Seive of eratosthenes is not enough.

    Now time for magic.

    Segmented seive
    -----------------
    In a question that has segmented seive like the prime number generator,
    it will the mentioned that the range of query will be <= 10^6.
    YOU SEE WHAT THEY DID THERE?
    This is the most obvious sign that you only need to store the range.
    Thats because you can only store the range.
    Anything greater than 10^6 is a problem.

    So now that we know we can only store the range, how do we do these things?

    We need to take a revisit of every thing we did from previous problems.
    Problem 1 (Introduction):
        Created the segment seive array
            - While creating the segmented seive array, we
                only took multiples from the square of the index.
                    j = i*i ; j<10000000; j=j+1
            - This was to skip all unnecessary nodes.
    Problem 4 (large prime check)
        Created the seive array
        Created vector that stores the primes.
        Then went upto squareroot of the number in the prime vector
        If any prime divided the large number, it was not prime.

    Here,
    What we need to do is.
        - Create the seive array
        - Create the vector that stores the prime.
        - Then from the range a to b, unset the multiples of each prime.
            Each prime upto the square root of n.
        - Also we will start from the starting range of the query.
            For eg. If we have a range of 99 to 144,
                    Then the first multiple of 2 that we take
                    should be 98. Since 98 doesnt exist, our next
                    step will be 100, 102, 104 and so on.
                    We get the start by,
                    (99/2) * 2 = 98

                    For 3, we will do the same thing
                    (99/3) * 3 = 99
                So our formula to get the starting number is.
                (a/primes[i]) * primes[i]
*/
#include<iostream>
#include<vector>
#define ll long long

using namespace std;

void prime_seive(int *p, vector<int> &primes) {
    // set 2
    p[2] = 1;
    primes.push_back(2);
    // set all odd numbers
    for(int i=3; i<1000000; i+=2) {
        p[i] = 1;
    }
    // now iterate
    for(int i=3; i<1000000; i+=2) {
        if(p[i] == 1) {
            primes.push_back(i);
            for(ll j=i*i; j<1000000; j=j+1) {
                p[j] = 0;
            }
        }
    }
}

int main() {
    int p[1000005] = {0};
    vector<int> primes;
    // construct p and primes
    prime_seive(p, primes);
    // take the query and create an array of that size.
    // since the query range lies within 10^7, we are good.
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int size = b - a;
        // create the dynamic array.
        bool res[size];
        // fill the whole array with false
        for(int i=0; i<size; i++) {
            res[i] = 0;
        }
        // get results
        for(int x: primes) {
            if(x*x>b) {
                break;
            }
            int start = (a/x) * x;
            if(x>=a && x<=b) {
                start = x*2;
            }
            for(int i=start; i<=b; i+=x) {
                res[i-a] = 1;
            }
        }

        for(int k=a; k<=b; k++) {
            if(res[k-a] == 0 && k!=1) {
                cout << k << endl;
            }
        }
        cout << endl;
    }
    return 0;
}