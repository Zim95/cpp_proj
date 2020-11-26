/*
Multi-maps: When we want duplicate keys
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

void print_map(multimap<string, int> m) {
    for(multimap<string, int>::iterator it=m.begin(); it != m.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
}

int main() {
    multimap<string, int> m;

    int n;
    cin >> n;
    while (n--){
        string s;
        int no;
        cin >> s >> no;
        m.insert(make_pair(s, no));
    }

    // find
    multimap<string, int>::iterator m1 = m.find("x"); // will return iterator not index.
    // direct access is not allowed because there can be duplicates.
    // We need to iterate and use if condition.

    m.erase("y"); // Will delete both the keys. The only way to delete one
                  // is to give it a range in iterators. Then pass the iterator
                  // to the erase method.

    // range iteration
    cout << "Range iteration" << endl;
    multimap<string, int>::iterator a1 = m.lower_bound("x");
    multimap<string, int>::iterator a2 = m.upper_bound("x");
    while (a1 != a2) {
         cout << a1->first << ":" << a1->second << endl;
         a1++;
         m.erase(a1->first);
    }

    // print
    cout << "Final print" << endl;
    print_map(m);

    // Interesting use case of maps:
    // map<Node *, bool> can be used to track if a linked list is visited or not.
    return 0;
}
