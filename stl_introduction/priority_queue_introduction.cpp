/*
Priority queues use heaps as the underlying data structure.
Some things about heap:
1. Its a perfect binary tree. i.e. All nodes have 2 children.
2. There's mainly three types:
    a. Max heap -
        - The root needs to be the biggest.
        - right_child, left_child <= root
        - And the same pattern is followed.
        - If there's an imbalance?
            -> If there is by any chance some child node > parent node
            -> Swap operations are done to bring it to the top.
            E.g. Rotations in AVL tree.
    b. Min heap - 
        - The root is the smallest.
        - right_child, left_child >= root.
            Left may be bigger than right. It doesnt matter.
            The root should be bigger than the children and thats it.
        - And the same pattern is followed.
        - If there's an imbalance?
            -> If there is by any chance some child node < parent node
            -> Swap operations are done to bring it to the top/
    c. Your custom heap -
        - Thats right!
        - You can pass custom functions that return the condition of truth.
        - Remember: In filter function? Only those items are returned, who yeild
                    true when passed through the filter function.
        - That is exactly what we need to do.
        - Pass a function based on which the sorting will be done.
3. Heaps are not trees. And we do not have Pre-order, Post-order and In-order.
   We actually represent them as arrays.
   We go from top, left, right
   And then create the array.

   This means that the root is at the 0th index.
   In case of max heap -> root is biggest -> Biggest element is at the 0th index.
   In case of min heap -> root is smallest -> Smallest element is at the 0th index.

   Formula: For any node at index i
   left child = 2i + 1
   right child = 2i + 2
   parent = (i - 1) / 2
   If parent is -(1/2). It means it is the root node and has no parent.

4. Insertion in max heap:
    '''
    insert at last.
    Swap until its below the correct root.
    '''
    
    def insert_heap(heap_list, number):
        if not heap_list:
            return heap_list.append(number)
        
        stop_looping = False
        number_index = len(heap_list)
        heap_list.append(number)

        # swap until biggest value is at the top
        while not stop_looping:
            parent_index = (number_index) / 2      
            parent = heap_list[parent_index]
            if number > parent:
                '''
                yes only greater.
                If the values are equal, we dont swap
                '''
                heap[parent_index] = number
                heap[number_index] = parent
                # new number_index
                number_index = parent_index
            else:
                stop_looping = True
        return heap_list

    Worst case:
        The worst case is, we enter values bigger than root.
        That way we need to get it to the top.
        This means the while loop will continue till the HEIGHT OF THE TREE.

        Height of tree - O(logn)
        How? Why?

        See we dont need to go through all nodes.

        We will only traverse one path not all the paths.
            Eg: left, left, root (or something like that)

        But mathematically, I have no clue how to prove it.
    Therefore, man the time complexity is O(logn).

    The condition reverses for min heaps.

5. Deletion in max heap:
    '''
    Swap with the last value.
    Then delete the last value.
    Balance the heap
    '''
    Not going to think of this one.

Learn more: https://www.youtube.com/watch?v=WCm3TqScBM8&t=2s

So priority queues are the array representation of the heap.
With push, pop, empty operations.

By default STL gives us a max heap.
We can use a min heap if required.

In STL, max heap is in descending order.
        min heap is in ascending order.
Custom heap, You know that better.

Opeartions on queue: front, back, push, pop
Operations on priority queue: front, back, top
*/

#include <iostream>
#include <queue>


using namespace std;


int main() {
    priority_queue<int> pq_max; // max heap -> min priority queue
    priority_queue<int, vector<int>, greater<int>> pq; // min heap -> max priority queue.

    int n = 2;
    while (n--) {
        int no;
        cin >> no;
        pq.push(no);
    }

    cout << pq.top() << endl; // get front value

    while(!pq.empty()) {
        int val = pq.top();
        cout << "queue value: "<< val << endl;
        pq.pop();
    }

    return 0;
}
