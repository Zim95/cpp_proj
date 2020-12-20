/*
First occurence of an element in the list
*/
#include<iostream>

using namespace std;

int recursive_first_occurence(int arr[], int n, int index) {
    if(index == 10) {
        return -1;
    }
    if(arr[index] == n) {
        return index;
    }else{
        return recursive_first_occurence(arr, n, index+1);
    }
}

int recursive_last_occurence(int arr[], int n, int index) {
    if(index == -1) {
        return -1;
    }
    if(arr[index] == n) {
        return 10-index;
    } else {
        return recursive_last_occurence(arr, n, index-1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "First Index of 9 = " << recursive_first_occurence(arr, 9, 0) << endl;
    cout << "First Index of 11 = " << recursive_first_occurence(arr, 11, 0) <<  endl;

    int arr_rev[] = {1, 2, 3, 4, 5, 5, 5, 7, 9, 10};
    cout << "Last Index of 5 = " << recursive_last_occurence(arr, 5, 9) << endl;
    cout << "Last Index of 11 = " << recursive_last_occurence(arr, 11, 9) <<  endl;
    return 0;
}