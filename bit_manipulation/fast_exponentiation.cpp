#include<iostream>

using namespace std;

int power_optimized(int a, int n) {
    /*
    Explanation:
    we need a**n = pow(a, n)
    Say, a = 2, n=5. Then, a**5 = 2**5 = 32

    We can say that, 5 = 1 0 1 = 1*(2**2) + 0*(2**1) + 1*(2**0) = 4 + 0 + 1
    So we can say that a**5 = a**4 * a**0 * a**1 = a**(4 + 0 + 1) = a**5
    We can also write this as
    => (a**4) * 1 + (a**2) * 0 + (a**1) * 1
    => a*a*a*a*1 + a*a*0 + a*1

    As you can see a will double each time.

    So each bit is multipled by power of 'a' times.
    The power of a doubles itself after every bit.
    */

    /*
    Example: 
            a = 3
            n = 5
            => 3^5
            => 3 ^ (101)
            => 3 ^ (1 * 2^2 + 0 * 2^1 + 1*2^0)
            => 3 ^ (1 * 2^2) * 3 ^ (0 * 2^1)  * 3 ^ (1 * 2 ^ 0) [By using the rule: a^(b+c) = a^b * a^c]----(i)
            => (3 ^ 4) * (3 ^ 0) * (3 ^ 1)
    */
    int ans = 1; // Initially ans is 1, because you multiply with 2^0 which is 1.
    while(n>0){
        int last_bit = (n&1);
        if(last_bit==1) {
            ans = ans*a;
        }
        a = a*a;
        /*
        increment power of a by 2.
        a = 3 -> (3^1)
        a = a * a = 3 * 3 = 9 -> (3^2)
        a = a * a = 9 * 9 = 81 -> (3^4)
        So, if the bit is 1, this power is multiplied to the cumulative answer.
        Otherwise not.
        */
        n = (n>>1);
    }
    return ans;
}

int main(){
    int a=2, n=4;
    cout << "2**4 = " << power_optimized(2, 4) << endl;
    return 0;
}