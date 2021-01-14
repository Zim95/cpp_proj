// QUERY
/*
    In the last tutorial. We built the tree.
    In this tutorial we will be querying the range.

    Case 1: Complete Overlap
    --------------------------
    Say you want to query from the range qs-qe.
    You are on the node which contains the answer for the range s-e.
    Such that s=qs and e=qe.
    In other words, you found the exact range.
    This is called the complete overlap.
    In this case, we will simply return the answer at the index of the node.
    return tree[index].

    Case 2: Partial Overlap
    ------------------------
    Say you want answer between 2-4, the node you are on has answer from 3-5.
    You have a partial overlap.
    In other words, be it smaller or larger, if part of your range is also a partial part of the range that the node contains.
    You have a partial overlap.
    In such cases you make a call to the left and right child
    And return the minimum/maximum/something of them.

    Case 3: No Overlap
    -------------------
    Say you want answer between 2-4, the node you're on has an answer of 5.
    Then there is no overlap.
    Return infinity.

    Note: This method will work even if your range is say 4-4.
            .i.e. Even if you're querying a single element.
*/
#include<iostream>
#include<climits>

using namespace std;

void build(int *a, int s, int e, int *tree, int index) {
    // base case: the start and end will be equal. Only one element.
    // Since we keep dividing the range. It will become 0 on the leaf node.
    if(s==e) {
        // here we assign the value in the tree.
        tree[index] = a[s]; // Since only one value. That becomes the value. Otherwise it will be the answer of range operation.
        return;
    }

    // Divide the range by 2.
    int mid = (s+e)/2;
    build(a, s, mid, tree, 2*index); // Left child;
    build(a, mid+1, e, tree, 2*index+1); // right child;

    // compare which one is smaller and put the value in the index.
    // left child is stored at 2*index.
    // right child is stored at 2*index+1.
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int query(int *tree, int s, int e, int qs, int qe, int index) {
    // complete overlap
    if(s>=qs && e<=qe) {
        return tree[index];
    }
    // no overlap
    if(qe<s || qs>e) {
        return INT_MAX;
    }
    // partial overlap
    int mid = (s+e)/2;
    int left = query(tree, s, mid, qs, qe, 2*index);
    int right = query(tree, mid+1, e, qs, qe, 2*index+1);
    return min(left, right);
}

int main() {
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);

    int *tree = new int[4*n+1];
    build(a, 0, n-1, tree, 1);

    // print the tree
    cout << "Segment tree is:" << endl;
    for(int i=1; i<(4*n+1); i++) {
        cout << tree[i] << ", ";
    }
    cout << endl;

    // query time
    cout <<  "Let's run some queries" << endl;
    int q;
    cin>>q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << query(tree, 0, n-1, l, r, 1) << endl;
    }
    return 0;
}