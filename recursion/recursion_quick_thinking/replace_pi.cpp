// Number to string
// Two Zero Four Eight -> 2048
#include<iostream>

using namespace std;

/*
    Replace Pi with 3.14
    ---------------------
    xpiypizpi1234 --> x3.14y3.14z3.141234

    NOTES:
    1. When you try to cout << char a[], you get garbage value printed.
    2. Always use single quotes for character comparison.
    3. The size of character array can be dynamically grown somehow. Weird. NO THIS IS BECAUSE THE SIZE IS ALREADY 1000.
    4. You dont need to know the size of the character array to terminate it. Just look for null. which is '\0'.
*/

void replace_pi(char *a, int i=0) {
    if(a[i]=='\0' || a[i+1]=='\0') {
        return;
    }
    if(a[i] == 'p' && a[i+1] == 'i') {
        int j = i+2; // Since a[i]=p and a[i+1]=i, a[i+2] is where we need to start shifting from.

        // increment j to end of the array.Until you get null
        while(a[j] != '\0') {
            j++;
        }
        j++; // To add null to the array

        // come back till i+2 and copy to new index.
        while(j>=i+2) {
            a[j+2] = a[j]; // this is where the copying happens. All items are shifted to the right by 2. No issue with size at all. Because array is already of size 1000.
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        replace_pi(a, i+4);
    } else {
        replace_pi(a, i+1);
    }
}

int main() {
    char a[1000] = "xpiypizpi1234";
    replace_pi(a);
    int i=0;
    while(a[i]!='\0') {
        cout << a[i];
        i++;
    }
    return 0;
}
