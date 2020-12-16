/*
Recursion Problems:
1. Binary Search.
2. Power.
3. Multiply two numbers without using * operator.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<int> v) {
    for(int x: v) {
        cout << x << ",";
    }
}

int binary_search(vector<int> arr, int key, int offset=0) {
    // first sort
    sort(arr.begin(), arr.end());
    
    int midpoint = int(arr.size()/2);
    if(arr[midpoint] > key) {
        // if range permits
        if (midpoint != 0) {
            vector<int> new_array(arr.begin(), arr.begin()+midpoint);
            int new_offset = offset;
            return binary_search(new_array, key, new_offset);
        } else {
            return -1; // Not found
        }
    } else if(arr[midpoint] < key) {
        // if range permits
        if (midpoint+1 < arr.size()) {
            vector<int> new_array(arr.begin() + midpoint + 1, arr.end());
            int new_offset = midpoint + 1 + offset;
            return binary_search(new_array, key, new_offset);
        } else {
            return -1; // Not found
        }
    }
    return (midpoint + offset);
}

int power_recursive(int n, int pow) {
    if (pow == 0) {
        return 1;
    }
    return n*power_recursive(n, pow-1);
}

int multiply_recursive(int n, int m){
    if (m == 0) {
        return 0;
    }
    return n+multiply_recursive(n, m-1);
}

int main() {
    // binary search problem
    vector<int> arr = {40, 50, 10, 20, 30}; // because this will be sorted. {1, 2, 3, 4, 5}
    int result = binary_search(arr, 4);
    cout << "Index of " << 10 << " is: " << binary_search(arr, 10) << endl;
    cout << "Index of " << 20 << " is: " << binary_search(arr, 20) << endl;
    cout << "Index of " << 30 << " is: " << binary_search(arr, 30) << endl;
    cout << "Index of " << 40 << " is: " << binary_search(arr, 40) << endl;
    cout << "Index of " << 50 << " is: " << binary_search(arr, 50) << endl;
    cout << "Index of " << 1 << " is: " << binary_search(arr, 1) << endl;

    // find power recursively
    cout << "power(5, 4) = " << power_recursive(5, 4) << endl;

    // multiply recursively
    cout << "multiply(5, 4) = " << multiply_recursive(5, 4) << endl;
    return 0;
}