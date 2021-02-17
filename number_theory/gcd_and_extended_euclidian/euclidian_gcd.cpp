/*
    GCD = HCF (No kidding)
    
    According to Euclid, the GCD of two numbers a and b is:
    - GCD(a, b) = GCD(b, a%b)
    - GCD(a, 0) = a

    Property of LCM
    GCD * LCM  = a x b
    So,
    LCM = (a x b)/GCD

    Time complexity:
    ================
    We know,
    GCD(a, b) = GCD(b, a%b)
    Now we need to know how many steps it'll take before reaching the base case.

    a%b will give us x, and x will lie in the range 0<x<b-1.
    Idk why, he never explains it, just something we should know.

    Also,
    We know that,
    a%b can be written as [a - the closest power of b] (Whatever the hell that means).
    But what this means is,
    a % b = a - [a/b] * b (How?? I have no clue. But if the man says this is how it is, then it must be true).

    So, we have,
    a % b = 0<x<b-1. -----(1)
    a % b = a - [a/b] * b -----(2)

    From equation 2 we can say that
    The minimum value of a/b will be 1. So we can say.
    a % b <= (a - b) -----(3)

    We know, a%b gives us x, so we can say,
    x <= a - b -----(4)

    Btw, we are assuming a > b in our case.

    We also have, from eq (1), x<b -----(5)

    Adding (4) and (5), we get.
    2x < a,
    x < a/2 - this motherfucker is a very important thing we derived.

    As someone who doesnt know how to deduce mathematical equations.
    This made no fucking sense.
    Need to learn mathematical deduction.

    So now that we know, x<(a/2), our gcd equation can be written as,
    => GCD(a, a%b)
    => GCD(b, a/2)
    => GCD(a/2, ...) (Because as you notice, b becomes a and right now our b is a/2, so a/2 comes in the front.)

    So it means,
    T(n) roughly= T(n/2) + k (What? How? WTF!)

    So this means logn
*/
#include<iostream>

using namespace std;

int gcd_euclid(int a, int b) {
    if(b == 0) {
        return a;
    }
    int result = gcd_euclid(b, a%b);
    return result;
}

int lcm_euclid(int a, int b, int gcd) {
    return (a * b)/gcd;
}

int main() {
    int a = 60;
    int b = 72;
    int gcd = gcd_euclid(a, b);
    int lcm = lcm_euclid(a, b, gcd);
    cout << "GCD: " << gcd << endl;
    cout << "LCM: " << lcm << endl;
}
