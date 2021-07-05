/*
    This is a question from SPOJ.
    Here we will understand the cycle property of modulus in a better way.

    The cycle property is something we already know:
    If a number divides another number,
    the remainder will be greater than the number.

    Eg:
    Divide any number by 2, the max remainder you get is 1.
    Divide any number by 3, the max remainder you get is 2.
    And so on,

    So,
    the cycle of modulo is,
    if a series of numbers: a1, a2, a3,.... is divided by n, then,

    The remainders are:
    0, 1, 2, ....., n-1, 0, 1, 2, ....., n-1 and the cycle continues.

    Say, series = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    And, n = 5
    Then
    1 % 5 = 1
    2 % 5 = 2
    3 % 5 = 3
    4 % 5 = 4
    5 % 5 = 0
    6 % 5 = 1
    7 % 5 = 2
    8 % 5 = 3
    9 % 5 = 4
    10 % 5 = 0

    So you see proof now.

    Now onto the question.

    Question:
    =========
    You are given two integeres a and b and q queries.
    Any i-th query contains two numbers l[i] and r[i],
    the answer to each query is a number x,
    such that,
    l[i] <= x <= r[i] (x is a number within the range)
    (x % a) % b != (x % b) % a



*/

// THIS PROBLEM IS BETTER EXPLAINED ON YOUTUBE. NEED TO WATCH THAT:
// https://www.youtube.com/watch?v=Ff4Sjgd6l00

/*
Youtube's explanation:
-----------------------
Thing to note:
1. say, we have a % b where a<b, we always get a.
    E.g
    Say, a=5, b=10
    a%b = 5

    Say, a=7, b=25
    a%b = 7

    Because, b cannot divide a and will return 0.
    The remainder will always be the original number which was to be moduloed (is that even a word?)

2. Like the above description said,
    divide any number by N and the max result youll get is N-1.

So knowing this,
Lets analyse something,
If we take x<b,
then lets look at the equations
(x % a) % b ----(i) and
(x % b) % a ----(ii)

We know x is less than b,

WATCH THE WHOLE VIDEO TO UNDERSTAND.
*/