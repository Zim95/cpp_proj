/*
    Adjacency list for weighted graphs.
    In our previous example, we were using integers as vertices.
    l[0], l[1] and so on.
    What if the vertices were strings.
    So we cannot use list for this.

    We also need to assign weights to the edges.
    So keeping those two things in mind we are using a hashmap (dictionary).

    Think of it like this:
    {
        'A': [('B', 20), ('C', 30)],
        'B': [('A', 20)],
        'C': [('A', 30)]
    }

    Except, we have to do it in C++, so we have
    key = string
    value = list<pair<string, int>>

    So our map would be,
    unordered_map<string, list<pair<string, int>>>
*/
#include<iostream>
#include<unordered_map>
#include<list>
#include<string>

using namespace std;

class Graph {
    int v;
    unordered_map<
        string,
        list<
            pair<string, int>
        >
    > m;
public:
    void add_edge(string a, string b, bool bidirectional, int w) {
        this->m[a].push_back(make_pair(b, w));
        if(bidirectional) {
            this->m[b].push_back(make_pair(a, w));
        }
    }

    void print_adjlist() {
        for(auto p: this->m) {
            cout << p.first << ":";
            for(auto c: p.second) {
                cout << "(" << c.first << ", " << c.second << ")" << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.add_edge("A", "B", true, 20);
    g.add_edge("B", "D", true, 30);
    g.add_edge("A", "C", true, 10);
    g.add_edge("C", "D", true, 40);
    g.add_edge("A", "D", false, 50);
    g.print_adjlist();
    return 0;
}
