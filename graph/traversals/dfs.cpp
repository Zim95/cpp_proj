/*
    This also covers connected components.
    I also already did journey to the moon.
    So that is covered. as well.
    So this covers - 3 lessons.
*/
#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class Graph {
    map<T, list<T>> m;
public:
    void add_edge(int a, int b) {
        this->m[a].push_back(b);
        this->m[b].push_back(a);
    }

    void dfs_helper(T node, map<T, bool> &visited, list<T> &connected) {
        visited[node] = true;
        connected.push_back(node);

        list<T> connections = this->m[node];        
        for(T connection: connections) {
            if(!visited[connection]) {
                dfs_helper(connection, visited, connected);
            }
        }
    }

    void dfs(T src) {
        map<T, bool> visited;
        for(auto p: this->m) {
            visited[p.first] = false;
        }
        list<int> connected_groups;
        for(auto p: this->m) {
            if(visited[p.first]) {
                continue;
            }
            if(this->m[p.first].empty()) {
                connected_groups.push_back(1);
                cout << p.first << endl;
                continue;
            }
            list<T> connected;
            dfs_helper(p.first, visited, connected);
            connected_groups.push_back(connected.size());
            print_connected_comps(connected);
        }
    }

    void print_connected_comps(list<T> connected_comps) {
        for(T connected_comp: connected_comps) {
            cout << connected_comp << "->";
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
    g.add_edge(5, 7);
    // g.print_adj();
    g.dfs(0);
    return 0;
}