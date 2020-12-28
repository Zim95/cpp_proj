/*
Subsequence / Subset Problem
Very important concept
==================================
Given a string of 8 characters, find out all the subsets of that string.

string = "abc"
subsets = ["", "a", "b", "c", "ab", "bc", "ac", "abc"]

Analysis:
---------
1. We have done this using bit manipulation once.
2. Now its time to do it with 

Rules:
------
1. If you have n items, then we can have 2^n subsets.
2. Subsequence/Subset and Subarray are not the same.
    In subarray the order should be the same.
    In subsequence, you can concatenate the first and last if you remove middle.

Algorithm:
----------
Say, s = "abc"
Then in recursion we can have,
We start with
a:
    [a] | []
b:
    [a,b] [a] | [b] []
c:
    [a, b, c] [a,b] | [ac] [a] | [bc] [b] | [] [c]

So we have two options: Either to include the current character that we are processing or not.
                        Then the rest can be left upto recursion.

We will do this by using arrays.

BONUS: Try and reverse the order of the output.
*/
#include<iostream>
#include<string>

using namespace std;

void generate_subsequence(char *ip, char *op, int i, int j) {
    if(ip[i]=='\0') {
        op[j] = '\0'; // to terminate the array.
        // this is where we get the subset.
        cout << "Subset: " << op << endl;
        return;
    }
    op[j] = ip[i]; // assign value
    generate_subsequence(ip, op, i+1, j+1); // by selecting the character
    generate_subsequence(ip, op, i+1, j); // by not selecting the character
    // in the second case j will not increment. This means it will be replaced by another character.
    // By doing that we omit the first character.
}

int main(){
    char input[]="abc";
    char output[10];
    generate_subsequence(input, output, 0, 0);
    cout << output << endl;
    return 0;
}
