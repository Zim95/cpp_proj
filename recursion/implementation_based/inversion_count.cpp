// Merge sort
#include <iostream>

using namespace std;

int inversionCountMergeSort(int *a, int s, int e) {
    
}

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
