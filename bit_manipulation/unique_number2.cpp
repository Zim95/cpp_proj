/*
We are given an array containg n numbers. 
All the numbers are present twice except for two numbers
which are present only once. Find the unique numbers in linear time
without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
    // input
    int n;
    cin>>n;
    cin.get();

    vector<int> input;
    input.reserve(n);

    int xor_result = 0;

    // input and final xor result
    while(n--){
        int no;
        cin >> no;
        input.push_back(n);
        // xor_result will be the final result from which we need to extract two numbers
        xor_result = (xor_result^no);
    }

    // now that we have the xor result we need to find the first set bit
    // and extract all numbers from the vector who have similar set bit at the same position.

    // get first set bit of xor result
    bool keep_looping = true;
    int temp_xor_result = xor_result;
    int first_set_position = 0;
    while(keep_looping){
        int last_bit = (temp_xor_result&1);
        if((last_bit == 1) || (temp_xor_result==0)) {
            keep_looping = false;
        } else {
            first_set_position += 1;
            temp_xor_result = (temp_xor_result>>1);
        }
    }

    // now we know where the first set position is
    // Let us find all numbers that have set bit at the position.
    // A concept is that: when we find each number we do a xor of them.
    // We will not find the other unique number because the other unique number will not have set bit at the particular position.
    // If both unique numbers had set bits at the same position, then the XOR of them would be zero.
    // Therefore, WE CAN BE SURE THAT WE WILL FIND ONLY ONE OF THE UNIQUE NUMBERS WHEN DOING THIS.

    // XORing all numbers that have set bit at the position will give us one of the unqiue numbers.
    int mask = (1<<first_set_position);
    int x = 0;
    for(int val:input) {
        if((val&mask)>0) {
            x = (x^val);
        }
    }

    // Now if we add this unique number to the list of input.
    // There will be only one other unique number left.
    // That is our second number.
    // Meaning our second number is xor_result ^ first unique number
    int y = (xor_result^x);

    // Now we have both of the unique numbers.
    // Lets print them in order.
    cout << min(x,y) << " " << max(x,y) << endl;
    return 0;
}