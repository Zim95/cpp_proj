// this check sorting only checks in ascending order.
#include<iostream>
#define MIN -123456789

using namespace std;

bool check_sorting(int index, int arr[], int previous) {
    // current should be greater than previous. Current Condition = true
    // same should hold true for index + 1. Next condition = true
    // Next condition will only happen if index+1 is not out of range.

    int length = 5; // Because we have hardcoded it. Since we know the size.
                    //Otherwise we would have to pass it to the function as well.
    int current = arr[index];
    bool current_condition = (current > previous);

    if (index+1!=5) {
        return (current_condition && check_sorting(index+1, arr, current));
    } else {
        return current_condition;
    }
}


int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 1, 4, 5};

    cout << "Arr1 is: " << (check_sorting(0, arr1, MIN)?"sorted":"unsorted") << endl;
    cout << "Arr2 is: " << (check_sorting(0, arr2, MIN)?"sorted":"unsorted") << endl;
    return 0;
}