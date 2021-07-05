#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class Graph{
    map<T, list<T>> m;
public:
    void add_edge(int a, int b) {
        this->m[a].push_back(b);
        this->m[b].push_back(a);
    }

    void print_adj() {
        for(auto p: this->m) {
            cout << p.first << ": ";
            for(T c: p.second) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    void bfs(T src) {
        map<T, int> visited;

        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << endl;
            for(T i: this->m[node]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }

        }
    }
};

int main() {
    Graph<int> g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.bfs(0);
    return 0;
}
