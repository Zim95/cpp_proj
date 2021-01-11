/*
    PERMUTATIONS:
    =============
    Main string: "abc"
    Find all options
    ------------------
    abc
    acb
    cab
    cba
    abc
    acb

    Same problem just that they need to unique and need to be in order

    eg: Main string: "aba"
    Permutations:
    --------------
    aba
    aab
    baa
    baa
    aba
    aab

    As you can see there are repititions.
*/
#include<iostream>
#include<string>
#include<set>

using namespace std;

void permutations(char *ip, int i, set<string> &s) {
    if(ip[i]=='\0'){
        string a(ip);
        s.insert(a);
        return;
    }
    for(int j=i; ip[j]!='\0'; j++) {
        swap(ip[i], ip[j]);
        permutations(ip, i+1, s);
        // Backtracking
        swap(ip[i], ip[j]); // Without this the array wont reset.
        // And we will have repeated permutation sets.
    }
}

int main(){
    char input[] = "aba";
    set<string> s;
    permutations(input, 0, s);

    for(set<string>::iterator it=s.begin(); it!=s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}