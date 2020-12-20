#include <iostream>

using namespace std;

int power(int a, int n) {
    /*
        a^3 = a * a^(2) = a * a * a * 1
        a^2 = a * a^(1) = a * a * 1
        a^1 = a * a^(0) = a * 1

    So idea is: a^n = a * a^(n-1)
    */
    if(n == 0) {
        return 1;
    }
    return a * power(a, n-1);
}

int fast_power(int a, int b) {
    /*
        a ^ 9 = a.(a^4)^2
        a ^ 4 = (a^2)^2
        a ^ 2 = (a^1)^2
        a ^1 = a
    
    So idea is: a^n = (a^(n/2))^2 if n is even
              : a^n = a.(a^(n/2))^2 if n is odd
    */
    if(b == 1) {
        return a;
    }
    if((b&1)==1) {
        // if odd
        return a * fast_power(a, int(b/2)) * fast_power(a, int(b/2));
    }else{
        // if even
        return fast_power(a, int(b/2)) * fast_power(a, int(b/2));
    } 
}

int main() {
    int a = 3;
    int n = 5;
    cout << "Power("<<a<<","<<n<<"): " << power(a, n) << endl;
    cout << "Fast Power("<<a<<","<<n<<"): " << fast_power(a, n) << endl;
    return 0;
}