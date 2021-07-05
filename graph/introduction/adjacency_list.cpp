#include<iostream>
#include<list>

using namespace std;

class Graph {
private:
    int v;
    list<int> *l;
public:
    // constructor
    Graph(int v) {
        this->v = v;
        this->l = new list<int>[v];
    }

    // add edge
    void add_edge(int a, int b) {
        this->l[a].push_back(b);
        this->l[b].push_back(a);
    }

    // print list
    void print_adjlist() {
        for(int i=0; i<this->v; i++) {
            cout << i << ": ";
            for(int conn:this->l[i]) {
                cout << conn << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);
    g.print_adjlist();
    return 0;
}
