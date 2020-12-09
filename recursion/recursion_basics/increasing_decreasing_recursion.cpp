#include<iostream>

using namespace std;

void print_ascending(int n) {
    if(n==0){
        cout << 0 << ",";
    } else {
        print_ascending(n-1);
        cout << n << ",";
    }
}

void print_descending(int n) {
    if(n) {
        cout << n << ",";
        print_descending(n-1);
    } else {
        cout << 0;
    }
}

int main() {
    int n;
    cin>>n;

    cout << "Ascending order:" << endl;
    print_ascending(n);
    cout << endl;
    cout << "Descending order:" << endl;
    print_descending(n);

    return 0;
}