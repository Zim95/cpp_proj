/*
Question:
-----------
- You have a ladder with N steps.
- You can take M steps at max.
- Calculate the ways a person can reach the top.

This is a tricky problem:

Core idea:
------------------
Think about the number of ways you can reach the Nth Step.
Say max steps = M = 3.

Then you can reach the top in 3 ways.
N-1 by taking a step of 1.
N-2 by taking a step of 2.
N-3 by taking a step of 3.

This means:
f(n) = f(n-1) + f(n-2) + f(n-3) // for m=3
So,
f(n) = f(n-1) + f(n-2) + ... + f(n-m)

Base case:
-----------
0 stairs: 1 way. Already on top.

Edge Case:
-----------
Number of steps can be greater than the number of stairs
M>N
Just return f(n).
Or better: return 0 for all negative results. When M>N.

For e.g. N=5, M=7
f(5) = f(5-1) + f(5-2) + f(5-3) + f(5-4) + f(5-5) + f(5-6) + f(5-7)
f(5) = f(4) + f(3) + f(2) + f(1) + f(0) + f(-1) + f(-2)

So incase of 0 and negative values we return 0

TODO: Come up with a pure recursive solution for this.
*/
# include<iostream>

using namespace std;

int f(int n, int m) {
    // if no stairs, you are already on top. 1 way to stand
    if (n == 0) {
        return 1;
    }
    // for edge case discussed above.
    if (n < 0) {
        return 0;
    }

    int total = 0;
    for(int i=1; i<m; i++) {
        total += f(n-i, m);
    }
    return total;
}

int main(){
    int t, n, m;
    cin>>t;
    cin.get();
    while(t--) {
        cin >> n >> m;
        cout << f(n, m) << endl;
    }
    return 0;
}