#include <iostream>
#include <vector>


using namespace std;


int main() {
    vector<int> a = {10, 20, 30, 40, 50};
    a.push_back(1); // append to end
    a.pop_back(); // remove last element
    a.insert(a.begin() + 3, 100); // insert in between
    a.insert(a.begin() + 3, 7, 11); // insert 11, 7 times at a.begin() + 3
    a.erase(a.begin() + 3); // delete at index
    a.erase(a.begin() + 3, a.begin() + 5); // delete a range of elements

    for (int item: a) {
        cout << item << ",";
    }

    // get the first element
    cout << endl << "a front: " << a.front() << endl; // get first element
    cout << "a back: " << a.back() << endl; // get last element

    // sizing operations
    cout << "Size of a before resize: " << a.size() << endl;
    cout << "Capacity of a before resize: " << a.capacity() << endl;
    a.resize(8); // resizes the vector
    cout << "Size of a after resize: " << a.size() << endl;
    cout << "Capacity of a after resize: " << a.capacity() << endl;
    cout << "Note: avoid resize" << endl;

    // all containers have, empty and clear
    vector<int> b(a.begin(), a.end());
    cout << "Is a empty? : " << b.empty() << endl;
    b.clear(); // clear the container
    cout << "Is a empty? : " << b.empty() << endl;

    // use reserve keyword to reserve the max number of elements in vector
    // Without reserving the capacity keeps doubling, after every push back
    // If reserved the capacity is doubled only when the reserve limit is exceeded by the number of elements.
    vector<int> c;
    c.reserve(10);
    for (int j = 0; j < 11; j ++) {
        int no;
        cin >> no;
        c.push_back(no);
        cout << "Capacity with reserve: " << c.capacity() << endl;
    }
    vector<int> d;
    for (int j = 0; j < 11; j ++) {
        int no;
        cin >> no;
        d.push_back(no);
        cout << "Capacity without reserve: " << d.capacity() << endl;
    }
    return 0;
}
