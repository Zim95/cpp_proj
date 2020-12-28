/*
    THE FAMOUS KNAPSACK PROBLEM:
    ============================
*/
#include<iostream>

using namespace std;

int profit(int *w, int *p, int N, int C) {
    if(N==0||C==0){
        return 0;
    }

    int ans=0;
    int inc, exc;
    inc = exc = 0;

    if(w[N-1]<=C){
        // We can only include item if its weight is within the capacity
        inc = p[N-1] + profit(w, p, N-1, C-w[N-1]); // Including the item.
        // inc = profit made by item + profit made by n-1 items.
    }
    exc = profit(w, p, N-1, C);
    // exc = profit made by n-1 items. Because we didnt include the item.

    ans = max(inc, exc);
    return ans;
}

int main() {
    int weights[] = {1, 2, 3, 5};
    int profits[] = {40, 20, 30, 100};

    int N=4;
    int C=7;

    cout << profit(weights, profits, N, C);
    return 0;
}
