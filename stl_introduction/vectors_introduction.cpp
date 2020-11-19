#include <iostream>
#include <vector>


using namespace std;


int main() {
    vector<int> a = {10, 20, 30, 40, 50}; // Direct assignment: Declaration and initialization
    vector<int> b(5, 10); // Vector of size 5 with default value of 10
    vector<int> c(a.begin(), a.end()); // Copying another vector
    vector<int> d{1, 2, 3, 4, 5, 7, 9}; // Direct assignment: Declaration and initialization
    vector<int> e; // Empty vector

    // iterating using iterators
    vector<int>::iterator as = a.begin();
    vector<int>::iterator ae = a.end();
    vector<int>::iterator bs = b.begin();
    vector<int>::iterator be = b.end();
    vector<int>::iterator cs = c.begin();
    vector<int>::iterator ce = c.end();
    vector<int>::iterator ds = d.begin();
    vector<int>::iterator de = d.end();

    bool itrtr_loop = true;
    while(itrtr_loop) {
        if (
            as == ae && bs == be &&
            cs == ce && ds == de
        ) {
            itrtr_loop = false;
        } else {
            if (as != ae) {
                cout << "itrtr A: " << (*as) << ",";
            }                
            if (bs != be) {
                cout << "itrtr B: " << (*bs) << ",";
            }
            if (cs != ce) {
                cout << "itrtr C: " << (*cs) << ",";
            }
            if (ds != de) {
                cout << "itrtr D: " << (*ds) << endl;
            }
            as = as != ae ? ++as: as;
            bs = bs != be ? ++bs: bs;
            cs = cs != ce ? ++cs: cs;
            ds = ds != de ? ++ds: ds;
        }
    }

    // iterating with normal index
    bool index_loop = true;
    int start = 0;
    while(index_loop) {
        if (
            start >= a.size() &&
            start >= b.size() &&
            start >= c.size() &&
            start >= d.size()
        ) {
            index_loop = false;
        } else {
            if (start < a.size()) {
                cout << "index A: " << (a[start]) << ",";
            }                
            if (start < b.size()) {
                cout << "index B: " << (b[start]) << ",";
            }
            if (start < c.size()) {
                cout << "index C: " << (c[start]) << ",";
            }
            if (start < d.size()) {
                cout << "index D: " << (d[start]) << endl;
            }
            start += 1;
        }
    }

    // iterating with for each loop. Cannot iterate over all at once.
    for (int item: a) {
        cout << "A for each: " << item << endl;
    }

    // push back
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        int no;
        cin >> no;
        e.push_back(no);
    }
    // print the contents of e:
    for (int item: e) {
        cout << "E after push back: " << item << endl;
    }

    // understand at memory level, the difference in using push_back and predefining size.
    // created with pre assigned size
    cout << "A size: " << a.size() << endl; // the number of elements in the vector
    cout << "A capacity: " << a.capacity() << endl; // the number of elements the vector can fit.
    cout << "A max size: " << a.max_size() << endl; // max vector size allowed
    // created without pre assigned size
    cout << "E size: " << e.size() << endl; // the number of elements in the vector
    cout << "E capacity: " << e.capacity() << endl; // the number of elements the vector can fit.
    cout << "E max size: " << e.max_size() << endl; // max vector size allowed
    
    cout << "As you can see, the size of e is 8, despite having 5 elements only." << endl;
    cout << "This is because vector doubles its size everytime a new element is added beyond the last element" << endl;
    cout << "This auto memory expansion is expensive. Therefore we need to pre assign size whenever possible" << endl;

    // how to only assign size
    vector<int> x(2);
    cout << "Size of x: " << x.size() << endl;
    cout << "Element 0 of x: " << x[0] << endl;

    return 0;
}
