/*
This is an introduction to segment tree.
Lets understand what kind of problems are solved by segment trees.

Consider:
=======================
We have an array,
a = [1, 3, 2, -5, 6, 4]

And, we have the following range based queries:
1. Sum of numbers within a range.
2. Minimum within a range.
3. Maximum within a range.

Lets go with minimum:
=====================
Brute force:
------------
-> Iterate through each and every element and find the minimum.
One query has O(N) runtime.
Q queries has O(QxN) runtime.

Another way:
-------------
-> Build a 2d matrix.
-> Store the answer for all the queries.
-> And simply fetch.

Retrieval takes O(1).
But creation of the matrix takes O(N^2).

So we need segment trees.

So we will be starting Segment trees from the next video.
*/