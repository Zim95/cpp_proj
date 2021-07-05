How to find GCD for huge ass numbers.

Given two numbers m and n, where,
n <= 10^7 (This is just within the range. In fact this is the max range.)
m <= 10^250 (What the actual fuck?)

We know,
GCD(m,n) = GCD(n, m%n)

Now we need to find m%n which is a problem because m is too large.

We can however apply the modulo property.

Say we have a number, as big as 10^9

(2345708001) % 7
This would normally be out of range, but wait

We can write this number as,

[(2 * 10^9) + (3 * 10^8) + (4 * 10^7) + (5* 10^6) + (7 * 10^5) + (0 * 10^4) + (8 * 10^3) + (0 * 10^2) + (0 * 10^1) + (1 * 10^0)] % 7

This can be written as:
(2 * 10^9)%7 + (3 * 10^8)%7 + (4 * 10^7)%7 + (5* 10^6)%7 + (7 * 10^5)%7 + (0 * 10^4)%7 + (8 * 10^3)%7 + (0 * 10^2)%7 + (0 * 10^1)%7 + (1 * 10^0)%7

These values can be easily calculated by using fast modulo exponentiation
in logn time.

So that is all.


