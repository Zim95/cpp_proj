/*
Three ways:
1. Pure iteration - O(N^2)
2. Outer loop recursively, One iteration - O(N^2)
3. Pure recursion
*/

#include<iostream>

using namespace std;

void print_array(int a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << ",";
    }
}

void bubble_sort_pure_recursion(int *c, int n, int k) {
    // final: completion of n.
    if(n==1) {
        return;
    }
    if(k==n-1) {
        // completion of all k for one value of n.
        // so now finally we reset k and change the value of n
        bubble_sort_pure_recursion(c, n-1, 0);
        return;
    }
    // comparison and swap
    if(c[k]>c[k+1]){
        swap(c[k], c[k+1]);
    }
    // completion of one k.
    bubble_sort_pure_recursion(c, n, k+1);
}

void bubble_sort_partial_recursion(int b[], int n) {
    if(n == 1) {
        return;
    }
    for(int k=0; k<n-1; k++) {
        if(b[k]>b[k+1]) {
            swap(b[k], b[k+1]);
        }
    }
    bubble_sort_partial_recursion(b, n-1);
}

int* bubble_sort_pure_iteration(int a[], int n) {
    /*
        5 4 1 2 3 - 0 and 1
        4 5 1 2 3 - 1 and 2
        4 1 5 2 3 - 2 and 3
        4 1 2 5 3 - 3 and 4
        4 1 2 3 5 - end of i=0

        4 1 2 3 5 - 0 and 1
        1 4 2 3 5 - 1 and 2
        1 2 4 3 5 - 2 and 3
        1 2 3 4 5 - 3 and 4
        1 2 3 4 5 - end of i=1
        ...  and so on.
        goes on until i=(n-i)
    */
    int *sorted_arr = new int(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
        print_array(a, n);
        cout << "End of i= " << i << endl;
    }
    for(int k=0; k<n; k++) {
        sorted_arr[k] = a[k];
    }
    return sorted_arr;
}

int main() {
    int a[] = {59, 42, 1, 2, 99, 1726, -1};
    int n = sizeof(a)/sizeof(int);

    // iterative bubble sort
    cout << "Iterative bubble sort" << endl;
    int *sorted_arr = bubble_sort_pure_iteration(a, n);
    print_array(sorted_arr, n);
    cout << endl;

    cout << "Outer recursion with inner loop" << endl;
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 9, 10, -1};
    bubble_sort_partial_recursion(b, 11);
    // since we are passing by address, changes are reflected in the original array.
    // This means that our bubble sort function can be void, since we dont have to return anything.
    print_array(b, 11);
    cout << endl;

    cout << "Pure recursive bubble sort" << endl;
    int c[] = {10, 9, 8, 7, 6, 5, 4, 3, 9, 10, -1};
    bubble_sort_pure_recursion(c, 11, 0);
    print_array(c, 11);
    return 0;
}