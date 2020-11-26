/*
Maps are used for storing pairs of values.
They can be used to mimic json

Internal data structure: self-balancing BST
This means that the keys are stored in order in maps.
This also means no duplicate keys.

Operations:
1. Insert: insert function
2. Query: find function
3. Delete: erase function
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;


bool key_exists_count(map<string, int> m, string key) {
    if (m.count(key)) {
        return true;
    } else {
        return false;
    }
}

bool key_exists_iterator(map<string, int> m, string key) {
    map<string, int>::iterator it = m.find(key);
    if (it != m.end()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    map<string, int> m;

    // insert into maps
    m.insert(make_pair("x", 1));

    // insert a pair
    pair<string, int> p;
    p.first = "y";
    p.second = 2;
    m.insert(p);

    // insert with key value
    m["z"] = 3;

    // find
    map<string, int>::iterator xit = m.find("x");
    map<string, int>::iterator yit = m.find("y");
    map<string, int>::iterator zit = m.find("z");
    if (xit != m.end() && yit !=m.end() && zit != m.end()) {
        // this means it is present in the map
        cout << "value fo x: "<< m["x"] << endl;
        cout << "value fo y: "<< m["y"] << endl;
        cout << "value fo z: "<< m["z"] << endl;
    } else {
        cout << "x is not in the map" << endl; 
    }
    
    // alternative way to see if it key or not
    if (m.count("x")) {
        cout << "x is present" << endl;
    } else {
        cout << "x is not present" << endl;
    }

    // erase
    m.erase("x");

    // try finding
    if (key_exists_count(m, "x")) {
        cout << "x is present" << endl;
    } else {
        cout << "x is not present" << endl;
    }

    // iterate over map with iterator
    cout << "Iterating with iterator" << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << ":" << it->second << endl;
    }

    // iterate with foreach
    cout << "Iterating with foreach" << endl;
    for(pair<string, int> p: m) {
        cout << p.first << ":" << p.second << endl;
    }

    // Did you notice that the keys are printed in lexicographic order
    // Thats ordered maps for you. 
    // The self balancing bst auto balances the keys in order.

    return 0;
}
