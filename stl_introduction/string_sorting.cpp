/*

*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


bool compare(string a, string b) {
    if (a.length() == b.length()) {
        // compare lexographically
        return a>b;
    }
    // return based on length rather than direct string comaprison
    return a.length() > b.length();
}


int main() {
    int n;
    cin >> n; // read n
    cin.get(); // to get rid of possible new lines after n.

    // reading n strings
    string s[100];
    for (int i=0; i<n; i++) {
        getline(cin, s[i]);
    }

    // sorting
    sort(s, s+n);

    // custom comparison, we can create our own comapre functions
    // (like filter functions in python, we define the condition of truth.)
    // Here also, we create a function and define the condition of truth.
    // NOTE: Unlike sorted function in python, we do not mention, on what basis we are to sort
    //      Rather, we provide the condition of truth. 
    sort(s, s+n, compare);

    // print string
    for (int i=0; i<n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
