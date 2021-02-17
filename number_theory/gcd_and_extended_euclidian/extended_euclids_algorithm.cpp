/*
    Extended euclid algorithm
    ===========================
    This is a very important topic.

    It will help us solve equations such as:
    Ax + By = GCD(A, B), Given A, B
    We need to find the values of x and y.

    We need this for two main reasons:
    1. To solve multiplicative modulo inverse.
    2. To solve linear diophantine equations.

    So lets get into it.

    We know from Euclid algorithm that:
    GCD(A, B) = GCD(B, A%B)

    So our equation becomes:
    => Ax + By = GCD(A, B) -----(1)
    => Bx1 + (A%B)y1 = GCD(B, A%B) [x becomes x1 and y becomes y1 
                                    because the same values of x and y
                                    does not satisfy the equation.
                                    So, the change happens.]
    We also know that,
    a%b = a - [a/b] * b
    So our equation becomes,
    => Bx1 + [A - (A/B)*B]y1 = GCD(A, B) [How did B become A and A%B become B again? IDK]
    => Bx1 + Ay1 - [(A/B)*B]y1 = GCD(A, B)
    => B(x1 - (A/B)y1) + Ay1 = GCD(A, B) ----(2)

    So from (1) and (2),
    Ax + By = Ay1 + B(x1 - (A/B)y1)

    So we can say that,
    x = y1 ----(3)
    y = (x1 - (A/B)y1) ----(4)

    Lets, take an example of A=18, B=30, then we get,
    => 18 * x + 30 * y = GCD(18, 30)
    => 30 * x1 + 18 * y1 = GCD(30, 18) [Not reverse!!!! We just set GCD(A, B) -> GCD(B, A%B)]
    => 18 * x2 + 12 * y2 = GCD(18, 12)
    => 12 * x3 + 6 * y3 = GCD(12, 6)
    => 6 * x4 + 0 * y4 = GCD(6, 0)

    We know that GCD(a, 0) = a
    => 6 * x4 = 6
    => x4 = 1
    And y4 == 0

    So in base case, x4 will be 1 and y4 will be 0

    From equation 3,
    x = y1, meaning y from a step down.
    So x1 = y2, x2 = y3 and so on.

    So we can say that this will be built up in bottom up fashion.
*/
#include<iostream>

using namespace std;

int x, y, GCD;

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


int main() {
    int a=18;
    int b=30;
    extended_euclidian(a, b);
    cout << x << ", " << y << endl;
    return 0;
}