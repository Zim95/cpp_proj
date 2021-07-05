/*
    Problem statement: https://www.spoj.com/problems/HOLI/
*/
#include<iostream>
#include<map>
#include<list>

using namespace std;

class Graph {
    map<int, list<pair<int, int> > > m;
public:
    void add_edges(int a, int b, int w) {
        this->m[a].push_back(make_pair(b, w));
        this->m[b].push_back(make_pair(a, w));
    }

    void print_adjlist() {
        for(auto p: this->m) {
            cout << p.first << " = ";
            for(auto l: p.second) {
                cout << "(" << l.first << ", " << l.second << "), ";
            }
            cout << endl;
        }
    }
};

int main() {
    return 0;
}
