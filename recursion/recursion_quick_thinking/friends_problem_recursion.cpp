/*
    Question:
    ===========
    - Given N friends who want to go to a party on their bikes.
    - Each guy can go alone or with a pillion rider. Single or Double.
    - Find the number of ways in which N friends can go to the party.

    My-Solution:
    =============
    If first rider goes single. The rest can go in n-1 ways.
    If first rider goes double. The rest can go in n-2 ways.
    So we get,
    f(n) = f(n-1) + f(n-2) ? Right?

    Actual Solution:
    =======================
    - But here's the catch.

    -> Before in the tiles problem: We had infinite number of tiles.
    -> Before in the ladders problem: We had n steps and m max steps. However, we could take the same step infinite number of times.
    These were pure permutation problems where only the arrangement of things matter.

    - However, in this question, we are to supposed to find the combination.
    - How?
      -> Well the guy needs to choose a friend. Since choosing is involved. We need to apply combinations
    This is a combination problem.

    So lets re-analyse the question:
    --------------------------------
    - If, the first guy goes alone:. Rest can go in (n-1) ways.
    - If, the first guy goes as a couple: Rest can go in (n-2) ways.

    But the guy also needs to choose one friend.
    So he can choose one friend in (n-1)C1 ways.

    So,
    f(n) = f(n-1) + (n-1)C1 * f(n-2)
    f(n) = f(n-1) + (n-1)!/1!(n-1-1)! * f(n-2)
    f(n) = f(n-1) + (n-1) * f(n-2)

    Base case:
    ----------
    f(0) : No ways. So return 1.

    Test:
    -----
    input - 3, output - 4
*/
#include<iostream>

using namespace std;

int f(int n) {
    if(n==0) {
        return 1;
    }
    if(n<0) {
        return 0;
    }
    return f(n-1) + ((n-1) * f(n-2));
}

int main() {
    int n;
    cin>>n;
    cout << f(n) << endl;
    return 0;
}