#include <iostream>

using namespace std;

int main() {
    /*
        Problem - 
        -> Given a list of numbers, where every number occurs twice except one.
           Find the unique number.
    */
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        int no;
        cin >> no;
        ans = ans^no;
    }
    cout << "Unique number: " << ans << endl;

    /*
        Advantage-
        1. No need to create list and all. We can do it it constant space.
        2. Also it is solved in O(n).
    */
    return 0;
}