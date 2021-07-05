#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>

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

    void shortest_path_bfs(T src) {
        map<T, int> dist;
        queue<T> q;

        // setting infinite distance for every node
        for(auto node_pair: this->m) {
            dist[node_pair.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << endl;
            for(T i: this->m[node]) {
                if(dist[i] == INT_MAX) {
                    q.push(i);
                    dist[i] = dist[node] + 1;
                }
            }
        }

        for(auto node_pair: this->m) {
            cout << "Node " << node_pair.first << " is at a distance of " << dist[node_pair.first] << " from " << src << endl;
        }
        cout << endl;
    }
};

int main() {
    Graph<int> g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    // g.print_adj();
    g.shortest_path_bfs(0);
    g.shortest_path_bfs(1);
    g.shortest_path_bfs(2);
    g.shortest_path_bfs(4);
    return 0;
}
