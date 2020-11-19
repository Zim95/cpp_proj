/*
Used when we have a sorted array.
It is faster than the find function.
Timecomplexity: O(logn)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // sorted array
    int arr[] = {10, 20, 30, 40, 40, 40, 50, 60, 70, 80, 90};
    // length of array
    int n = sizeof(arr)/sizeof(int);

    // read key
    int key1 = 40;
    int key2 = 41;

    // first check if present or not
    bool present1 = binary_search(arr, arr+n, key1);
    if (present1) {
        // address of element >= key
        int *lb1 = lower_bound(arr, arr+n, key1); // --> address of first occurence of >=40 --> address_3rd_element
        int lb_index1 = lb1 - arr; // --> address_3rd_element - address_0th_element = 3, arr[3] = 40

        // address of elelment > key
        int *ub1 = upper_bound(arr, arr+n, key1); // --> address of first occurence of >40 --> address_6th_element
        int ub_index1 = ub1 - arr; // --> address_6th_element - address_0th_element = 6, arr[6] = 50

        /*
        NOTE: if lb == ub, it means that the key is not in the list.
        */
        
        // frequency of 40
        int frequency1 = ub_index1 - lb_index1; // --> 3

        cout << key1 << "::lower_bound: " << lb_index1 << ", lower_bound_index_value: " << arr[lb_index1] << endl;
        cout << key1 << "::upper_bound: " << ub_index1 << ", upper_bound_index_value: " << arr[ub_index1] << endl;
        cout << key1 << "::frequency: " << ub_index1 - lb_index1 << endl;
    } else {
        cout << key1 << " is not in the array" << endl;
    }

    bool present2 = binary_search(arr, arr+n, key2);
    if (present1) {
        cout << "Found" << endl;
    } else {
        cout << key1 << " is not in the array" << endl;
        // address of element >= key
        int *lb2 = lower_bound(arr, arr+n, key2); // --> address of first occurence of >=40 --> address_6th_element
        int lb_index2 = lb2 - arr; // --> address_6th_element - address_0th_element = 6, arr[6] = 50

        // address of elelment > key
        int *ub2 = upper_bound(arr, arr+n, key2); // --> address of first occurence of >40 --> address_6th_element
        int ub_index2 = ub2 - arr; // --> address_6th_element - address_0th_element = 6, arr[6] = 50

        /*
        NOTE: if lb == ub, it means that the key is not in the list.
        */
        
        // frequency of 41
        int frequency2 = ub_index2 - lb_index2; // --> 0

        cout << key2 << "::lower_bound: " << lb_index2 << ", lower_bound_index_value: " << arr[lb_index2] << endl;
        cout << key2 << "::upper_bound: " << ub_index2 << ", upper_bound_index_value: " << arr[ub_index2] << endl;
        cout << key2 << "::frequency: " << ub_index2 - lb_index2 << endl;
    }
    return 0;
}
