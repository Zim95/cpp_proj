// Building the segment tree.
/*
    Consider the array:
        a = [1, 3, 2, -5, 6, 4]
    We need to find the minimum from range 0-5.

    The segment tree would look as follows:
                    Soln(0-5)
                        |
                -------------------------
                |                       |
              Soln(0-2)                Soln(3-5)
                |                        |
            --------------          -----------------
            |            |          |               |
        Soln(0-1)       Soln(2)   Soln(3-4)     Soln(5)
            |                       |
        ---------                 ---------
        |       |                 |        |
      Soln(0)  Soln(1)        Soln(3)  Soln(4)
    
    From this tree:
    ===========================
    Soln(0) - a[0] - 1
    Soln(1) - a[1] - 3
    Soln(0-1) - Soln(0), Soln(1) - 1
    Soln(2) - a[2] - 2
    Soln(0-2) - Soln(0-1), Soln(2) - 1, 2 - 1
    And so on....
    The final answer we get will be -5.

    There are 3 operations involved.
    1. Build
    2. Query
    3. Update

    Build:
    ------
    We build the tree as an array. We go left to right
    Just like a heap.

    And just like in a heap:
    Formula: For any node at index i
    left child = 2i + 1
    right child = 2i + 2
    parent = (i - 1) / 2
    If parent is -(1/2). It means it is the root node and has no parent.

    If a node is not at the level of the other leaf nodes.
    And the node also does not have children.
    Then, we will assign garbage values for the left and right child.

    The size of the array that is formed will at max be of the size: (4N+1)
*/
#include<iostream>

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
    return 0;
}