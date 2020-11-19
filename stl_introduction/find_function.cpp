#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // the array
    int arr[] = {1, 10, 11, 110};
    // length of array
    int n = sizeof(arr)/sizeof(int);

    int key;
    // take input
    cin >> key;

    // get address of key
    auto key_address = find(arr, arr+n, key);
    int index = key_address - arr;

    if (index == n) {
        // this means didnt find:
        // Because: difference between address of first element
        // and address of the key should be less than the total length
        // otherwise the key is not in the array.
        cout << key << " is not in the array"<<endl;
    } else {
        cout << "Found " << key << " at: "<<index<<endl;
    }


    return 0;
}