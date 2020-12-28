/*
    Phone keypad problem:
    ---------------------
    You have a phone keypad with old keypad settings.
    i.e. To print c you need to press the number 2, 3 times.

    The keypad is mapped as follows:
    0 - ""
    1 - ""
    2 - "ABC"
    3 - "DEF"
    4 - "GHI"
    5 - "JKL"
    6 - "MNO"
    7 - "PQRS"
    8 - "TUV"
    9 - "WXYZ"

    Given a series of number presses.
    Generate all possible combinations of characters for the numbers.

    E.g.
    2 3 4

    ABC DEF GHI

    ADG
    ADH
    ADI
    AEG
    AEH
    AEI
    AFG
    AFH
    AFI
    ...
    Now for B and so on.

    So our recursion is like:
    Include A or
    include B or
    Inlcude C
    Then let the rest of the things form by recursion.

    Similar to subsequence problem. Go there to understand how the base case and the function works.
*/
#include<iostream>

using namespace std;

char km[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *ip, char *op, int i, int j) {
    // base case
    if(ip[i]=='\0'){
        op[j] = '\0';
        cout << op << endl;
        return;
    }
    int digit = ip[i] - '0';
    if(digit==1 || digit==0){
        generate_names(ip, op, i+1, j); // output index will not increase, we simply move to next digit in input.
    }

    for(int k=0; km[digit][k] !='\0'; k++) {
        op[i] = km[digit][k];
        generate_names(ip, op, i+1, j+1);
    }
    return;
}

int main(){
    char input[] = "237";
    char output[1000];

    generate_names(input, output, 0, 0);
    
    return 0;
}