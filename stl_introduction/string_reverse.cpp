#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    // string s="Hello World";
    string s;
    getline(cin, s);
    string rev="";
    for(string::iterator it=--s.end(); it!=--s.begin(); it--) {
        rev += (*it);
    }
    cout << rev << endl;
}
