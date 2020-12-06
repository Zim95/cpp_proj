/*
===================================================
This is more of set theory than bit manipulation.
===================================================
*/

/*
Say we have to sets, A and B.
Then,
|AUB| = |A| + |B| (If they are independent events).
|AUB| = |A| + |B| -|AintersectionB| (If they are inclusive events).

If we have 3 variables,
|AUB| = |A| + |B| + |C| (If they are independent events).
|AUB| = |A| + |B| + |C| -|AIntersectionB| - |BIntersectionC| - |CIntersectionA| + |AIntersectionBIntersectionC| (Inclusive events).

So the pattern is
If we are intersecting even number of sets, we need to subtract.
If we are intersecting odd number of sets, we need to add.

So, if a set has odd number of elements, we need to add and subtract if even.
*/

/*
Example problem 1:
Find all numbers less than 1000 that are divisible by 2, 3 and 5.

Steps:
-------
S1 = {All numbers less than 1000, divisible by 2} = int(999/2) = 499
S2 = {All numbers less than 1000, divisible by 3} = int(999/3) = 333
S3 = {All numbers less than 1000, divisible by 5} = int(999/5) = 199

S1.intersection(S2) = {All numbers less than 1000, divisible by 2 and 3} = int(999/2.3) = int(999/6) = 166
S1.intersection(S3) = {All numbers less than 1000, divisible by 2 and 5} = int(999/2.5) = int(999/10) = 99
S2.intersection(S3) = {All numbers less than 1000, divisible by 3 and 5} = int(999/3.5) = int(999/15) = 66

S1.intersection(S2).intersection(s3) = {All numbers less than 1000, divisible by 2, 3 and 5} = int(999/2.3.5) = int(999/30) = 33

So total ways = 
    499+333+199 - 166 - 99 - 66 + 33
    = 733 numbers

NOTE THE DIFFERENCE:
S1.intersection(S2).intersection(s3) is divisble by all 3 numbers.
We need to also add those that are not divisble by all 3, but only by 2 or only by 1.
So, that is the difference.
*/

/////////////////////////////// PROBLEM 1 ///////////////////////////////////////
/*
How many numbers between 1 and n are divisible by prime numbers between 1 and 20
Solution steps:
1. We need to get the subset divider. i.e. the denominator formed by each subset.
2. We need to then divide n by the denominator.
3. If the count of the subset is odd then we add the result, else we subtract the result.
*/
/////////////////////////////// Probelm 1 //////////////////////////////////////
#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int getSubsetDivider(int i, ll primes[]) {
    int subset_divider=1;
    int primes_index = 0;
    int subset_count = 0;
    while(i){
        int last_bit = (i&1);
        if(last_bit) {
            subset_divider *= primes[primes_index];
            subset_count++;
        }
        primes_index++;
        i = (i>>1);
    }
    if((subset_count&1)==0) {
        // if even turn it negative
        subset_divider = (-1 * subset_divider);
    }
    return subset_divider;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19}; // all primes less than 20
        int primes_subsets_length = (1<<8); // 2 pow 8
        int final_result = 0;
        for(int i=1; i<=primes_subsets_length; i++) {
            int subset_divider = getSubsetDivider(i, primes);
            int result = int(n/subset_divider);
            final_result += result;
        }
        cout << final_result << endl;
    }
    return 0;
}