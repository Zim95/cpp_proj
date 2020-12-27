// Number to string
// 2048 -> Two Zero Four Eight
#include<iostream>
#include<string>

using namespace std;

char words[][10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void number_to_string(int n) {
    if(n==0) {
        return;
    }
    int rem = n % 10;
    number_to_string(n/10);
    cout << words[rem] << " ";
}

int main() {
    number_to_string(2048);
}
