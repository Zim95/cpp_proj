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
*/
#include<iostream>

using namespace std;

void permutations(char *ip, int i) {
    if(ip[i]=='\0'){
        cout << ip << endl;
        return;
    }
    for(int j=i; ip[j]!='\0'; j++) {
        swap(ip[i], ip[j]);
        permutations(ip, i+1);
        // Backtracking
        swap(ip[i], ip[j]); // Without this the array wont reset.
        // And we will have repeated permutation sets.
    }
}

int main(){
    char input[] = "abc";
    permutations(input, 0);
    return 0;
}