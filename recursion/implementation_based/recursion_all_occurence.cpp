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
        return index;
    } else {
        return recursive_last_occurence(arr, n, index-1);
    }
}

int* recursive_all_occurrence(int *arr, int arrsize, int key, int *occurence_list, int index=0, int occurence_index=0) {
    // return a list of all occurences.
    if (index == arrsize) {
        int *result = new int(arrsize);
        for (int i=0; i<arrsize; i++) {
            result[i] = occurence_list[i];
        }
        return result;
    }
    if (arr[index] == key) {
        occurence_list[occurence_index] = index;
        occurence_index++;
    }
    index++;
    return recursive_all_occurrence(arr, arrsize, key, occurence_list, index, occurence_index);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "First Index of 5 = " << recursive_first_occurence(arr, 9, 0) << endl;
    cout << "First Index of 11 = " << recursive_first_occurence(arr, 11, 0) <<  endl;

    int arr_rev[] = {1, 2, 3, 4, 5, 5, 5, 7, 9, 10};
    cout << "Last Index of 5 = " << recursive_last_occurence(arr_rev, 5, 9) << endl;
    cout << "Last Index of 11 = " << recursive_last_occurence(arr_rev, 11, 9) <<  endl;

    int arr_all[] = {1, 2, 3, 4, 5, 5, 5, 7, 9, 10};
    int arrsize = 10;
    int occurence_list[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int *result = recursive_all_occurrence(arr_all, arrsize, 5, occurence_list);
    cout << "All occurences" << endl;
    for(int i=0; i<10; i++) {
        if (result[i] > 0) {
            cout << result[i] << endl;
        }
    }
    return 0;
}