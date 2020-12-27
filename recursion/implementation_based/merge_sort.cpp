// Merge sort
#include <iostream>

using namespace std;

void printArray(int *a, int n) {
    for(int p=0; p<n; p++) {
        cout << a[p] << ",";
    }
}

void merge(int *a, int s, int e) {
    int mid = (int)(s+e)/2;
    int i=s;
    int j=mid+1;

    int temp[100];
    int counter=s;

    while(i<=mid && j<=e) {
        if(a[i] < a[j]) {
            temp[counter++] = a[i++];
        } else {
            temp[counter++] = a[j++];
        }
    }

    while(i<=mid) {
        temp[counter++] = a[i++];
    }
    while(j<=e) {
        temp[counter++] = a[j++];
    }

    for(int k=s; k<=e; k++) {
        a[k] = temp[k];
    }
}

void mergeSort(int *a, int s, int e) {
    if(s==e) {
        return;
    }
    int mid = (int)(s+e)/2;
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);
    merge(a, s, e);
}

int main() {
    int ar[] = {10, 9, 8, 7, 6, 5, 4, -1, -2, 10};
    int n = 10;
    mergeSort(ar, 0, n-1);
    printArray(ar, n);
    cout << endl;
}
