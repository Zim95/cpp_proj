/*
    Given a mapping of characters and numbers.
    Print all possible string interpretations of a sequence of numbers.

    E.g.
    Say, s = "1234"
    - "1234" -> "ABCD"
    - "(12)34" -> "LCD"
    - "1(23)4" -> "AZD"
    - "12(34)" -> No -> Subset greater than 26
    - "(123)4" - No -> Subset Greater than 26
    - "1(234)" - No -> Subset Greater than 26
    - "(1234)" - No - Subset greater than 26

    Solution:
    ----------
    Here we have two choices:
    1. Pick 1 as a number and recursive call on 234.
    2. Pick 12 as a number and recursive call on 34.
    3. We cannot pick a subset larger than 2 in length. Because it will be greater than 26.
*/
#include<iostream>

using namespace std;

char km[] = {
    'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X',
    'Y', 'Z'
};
void generate_strings(char *ip, char *op, int i, int j) {
    if(ip[i]=='\0'){
        op[j]='\0';
        cout << op << endl;
        return;
    }
    int d1 = ip[i] - '0';
    // Handling case for 0 because the formula wont work for 0.
    if(d1>0) {
        op[j] = d1 + 'A' - 1; // get character from digit
        generate_strings(ip, op, i+1, j+1);
    }

    int d2 = 0;
    if(ip[i+1]!='\0'){
        d2 = (d1*10) + (ip[i+1] - '0'); // considering 12 as a digit.
        if(d2<=26 && d2>0) {
            op[j] = d2 + 'A' - 1;
            generate_strings(ip, op, i+2, j+1);
        }
    }
    return;
}

int main() {
    char input[] = "122212";
    char output[1000];

    generate_strings(input, output, 0, 0);

    return 0;
}
