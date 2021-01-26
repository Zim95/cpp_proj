/*
    Range updates in segment trees.
    -------------------------------
    If you find a particular range,
    Update all of its child nodes.
    Meaning, update each leaf node and build the tree up from there.
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

void point_update(int *tree, int s, int e, int point, int val, int index) {
    // base case: found the point to update
    if(s==e && s==point) {
        tree[index] += val;
        return;
    }
    // if not within range
    if(point>e || point<s) {
        return;
    }
    // this means within the range. Make a call to the left and right
    int mid = (s+e)/2;
    point_update(tree, s, mid, point, val, 2*index);
    point_update(tree, mid+1, e, point, val, 2*index+1);
    // after making the call build the tree
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void range_update(int *tree, int s, int e, int l, int r, int val, int index) {
    // out of bounds
    if(l<s || r>e) {
        return;
    }
    // leaf node
    if(s==e) {
        tree[index] += val;
        return;
    }
    // this means within the range. Make a call to the left and right
    int mid = (s+e)/2;
    range_update(tree, s, mid, l, r, val, 2*index);
    range_update(tree, mid+1, e, l, r, val, 2*index+1);
    // after making the call build the tree
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
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

    // point updates
    point_update(tree, 0, n-1, 3, 10, 1);

    // query time
    cout <<  "Let's run some queries" << endl;
    cin>>q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << query(tree, 0, n-1, l, r, 1) << endl;
    }

    // range updates
    range_update(tree, 0, n-1, 0, 5, 10, 1);
    // print the tree
    cout << "Segment tree is:" << endl;
    for(int i=1; i<(4*n+1); i++) {
        cout << tree[i] << ", ";
    }
    cout << endl;
    return 0;
}
