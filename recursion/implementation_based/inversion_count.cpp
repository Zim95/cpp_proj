/*
    INVERSION COUNT
    ---------------
    Given an array:
    int a[] = {1, 5, 2, 6, 3, 0, 2};
    Find all pairs such that,
    a[i] > a[j], for all i<j.

    You see its inverted. As according to sorting, if i<j, a[i]<a[j].
*/
#include <iostream>

using namespace std;

int inversionCountMergeSort(int *a, int s, int e) {
    // Base case
    if(s>=e) {
        // End of array return 0 inversions.
        return 0;
    }
    
}

// Brute force technique
int inversionCountBruteForce(int *a, int n) {
    int inversion_count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if((a[i] > a[j]) && i<j) {
                inversion_count++;
            }
        }
    }
    return inversion_count;
}

int main() {
    // int ar[] = {10, 9, 8, 7, 6, 5, 4, -1, -2, 10};
    int ar[] = {1, 5, 2, 6, 3, 0};
    int n = 6;
    int ic = inversionCountBruteForce(ar, n);
    cout << "Inversion count: " << ic << endl;
    cout << endl;
}
