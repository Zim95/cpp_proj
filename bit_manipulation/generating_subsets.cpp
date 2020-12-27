#include<iostream>
#include<string>
#include<math.h>

using namespace std;

string generateSubstringFromN(int n, string s) {
    int string_index = 0;
    string substring = "";
    while(n>0) {
        int last_bit = (n&1);
        if (last_bit) {
            substring += s[string_index];
        }
        string_index++;
        n = (n>>1);
    }
    return substring;
}

int main() {
    /*
        Generate all possible subsets of a string.
        1. Create a function that takes in n and returns a substring. E.g. generateSubstringFromN(5, "abc") -> "ac"
            As in, 101 for abc = ac.
        2. Run this for i=0 to n
    */
    string input;
    getline(cin, input);
    int total_subsets = pow(2, input.length()); // for n ->3, we have 8 combinations.
    cout << total_subsets << endl;
    for (int i=0; i<total_subsets; i++) {
        cout << "Subset for " << i << " = " << generateSubstringFromN(i, "abc") << endl;
    }
    return 0;
}