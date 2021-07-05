/*
    Multiplicative Modulo Inverse:
    ==============================
    First lets consider multiplicative inverse.

    Multiplicative inverse:
    -----------------------
    We have a number a, we need to find the  number b such that,
    a.b = 1
    This means, a = 1/b.

    Here we are talking about multiplicative modulo inverse.

    Multiplicative Modulo inverse:
    -------------------------------
    We have a number a, and modulo m, then,
    find the number b such that,
    (a.b)%m = 1
    
    Proving the final equation:
    ----------------------------
    We have, (a.b)%m = 1
    This means,
    (a.b)%m - 1 = 0
    Now, the dude does some fuckery and got
    ab - 1 = km
    He says, [(a.b)%m -1]%m = 0, so this shows that
    (ab) - 1 = km (How? What the fuck? I actually gave up trying to understand)

    So far, we have
    ab - 1 = km
    ab - km = 1
    ab + (-k)m = 1

    Now this equation is of the form
    Ax + By = GCD(A, B)
    Only if, GCD(A, B) = 1

    So the value of X, i.e. b in this equation will be the modulo
    multiplicative inverse

*/
#include<iostream>

using namespace std;

int x, y, GCD;

int gcd_euclid(int a, int b) {
    if(b == 0) {
        return a;
    }
    int result = gcd_euclid(b, a%b);
    return result;
}

void extended_euclidian(int a, int b) {
    if(b==0) {
        x=1;
        y=0;
        GCD = a;
        return;
    }

    extended_euclidian(b, a % b);
    int cx = y;
    int cy = x - (a/b) * y;

    x = cx;
    y = cy;
}

int inverseModulo(int a, int m) {
    if(gcd_euclid(a, m) != 1) {
        // this thing will work only if gcd of a and m is 1.
        return -1;
    }
    extended_euclidian(a, m);
    // now the value of x and y are set.
    // the value we want is x.
    
    // return x;

    // Originaly the value of x might be -1.
    // To make it positive we add m and modulo m.
    // I mean, just in case it is negative, we turn it positive.

    return (x+m)%m;
}

int main() {
    cout << inverseModulo(6, 7) << endl;
    return 0;
}

// Safe to say:
// I did not understand shit from this problem
// But we need to remember this algorithm.
// For questions like these.