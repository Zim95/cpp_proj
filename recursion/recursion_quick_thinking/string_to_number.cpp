// Number to string
// Two Zero Four Eight -> 2048
#include<iostream>
#include<string>

using namespace std;

int string_to_number(char *a, int n) {
    if(n==0) {
        return 0;
    }
    /*
        "n" - "0" = n. This is how we get the digit.
        Why a[n-1]? Because we want the last digit.
        we do:
        For "1234", 0:
        : return 0

        For "1234", 1:
        : 1 + fn("1234", 0) * 10
        : 1 + 0
        : 1

        For "1234", 2:
        : 2 + fn("1234", 1) * 10
        : 2 + 10
        : 12 

        :fn("1234", 3)
        : 3 + (fn("1234", 2) * 10)
        : 3 + (12 * 10)
        : 3 + 120
        : 123

        For 1234
        : fn("1234", 4)
        : 4 + (fn("123", 3) * 10) -> Using "For 123"
        : 4 + (123 * 10)
        : 4 + 123
        : 1234
    */
              
    int an = a[n-1] - '0';
    return an + (string_to_number(a, n-1) * 10);
}

int main() {
    char a[] = "1234";
    int n = 4;
    int result = string_to_number(a, n);
    cout << result << endl;
    return 0;
}
