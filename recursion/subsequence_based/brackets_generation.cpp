/*
    Generate Brackets Recursion:
    ============================

    Question:
    ---------
    Generate balanced brackets using N pair of round brackets

    Analysis:
    ---------
    N=1, One pair. two brackets
    () -  1 way

    N = 2, Two pairs. Four brackets.
    ()()
    (()) - 2 ways

    N=3, Three pairs.
    ()()()
    (())()
    ()(())
    (()())
    ((())) - 5 ways

    N=4, Four pairs
    ()()()()
    (()()())
    ((())())
    (()(()))
    ((()()))
    (((())))
    (()())()
    ((()))()
    ()(()())
    ()((())) - 8 ways

    and so on.

    So,
    If n=2, we have 4 spaces to fill.
    - We can put ( bracket if:
        total opening bracket < 2
    - We can put ) bracket if:
        total closing bracket < 2
        total opening bracket > total closing bracket 

*/
#include<iostream>

using namespace std;

void generate_brackets(char *o, int n, int tob=0, int tcb=0, int index=0){
    // end case
    if(index==2*n){
        o[index] = '\0';
        cout << o << endl;
        return;
    }

    if(tob<n) {
        o[index] = '(';
        generate_brackets(o, n, tob+1, tcb, index+1);
    }

    if(tcb<tob) {
        o[index] = ')';
        generate_brackets(o, n, tob, tcb+1, index+1);
    }
    return;
}

int main() {
    int n;
    cin>>n;

    char output[1000];

    generate_brackets(output, n, 0, 0, 0);
    return 0;
}