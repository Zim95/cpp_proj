/*
We are learning how to split strings.
But in CPP, the process is called tokenizing strings.

Function definition:
char *strtok(char *s, char *delimeters)

So, we pass a char array (not string) and the delimeter.
It would look something like
 - strtok("Hello world", " ")
Maybe
No it does not look like that.
See what it looks like in the code.
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>


using namespace std;


int main() {
    char s[100] = "Hello World";
    char *result = strtok(s, " ");
    cout << result << endl; // --> Hello (only returns first substring)

    // What if we want the whole thing as a list?
    // Ans - We need to make consecutive calls to strtok.
    //       But instead of passing the character array, 
    //       We pass NULL as the string. When we do this,
    //       strtok saves a static copy of the string and the latest copy
    //.      will be further processed. In our case, the latest copy is str.
    char str[100] = "I want to print this entire string as an array";
    char *ptr = strtok(str, " ");
    vector<char *> rslt;
    cout << ptr << ",";
    while (ptr != NULL) {
        ptr = strtok(NULL, " ");
        // NOTE: character pointers can be printed as strings.
        // cout << ptr << endl;
        // Now what about storing it?
        rslt.push_back(ptr);
    }
    
    // print vector result
    for (vector<char *>::iterator v=rslt.begin(); v != rslt.end(); v++) {
        cout << *v << ",";
    }
    cout << endl;
    return 0;
}