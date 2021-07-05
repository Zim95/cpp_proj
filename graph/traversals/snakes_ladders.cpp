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

    int shortest_path_bfs(T src, T dest) {
        map<T, int> dist;
        map<T, T> parent; // to print path.
        queue<T> q;

        // setting infinite distance for every node
        for(auto node_pair: this->m) {
            dist[node_pair.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src; // parent of source is source.

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(T i: this->m[node]) {
                if(dist[i] == INT_MAX) {
                    q.push(i);
                    dist[i] = dist[node] + 1;
                    // update parent as well
                    parent[i] = node;
                }
            }
        }

        // print path
        T temp = dest;
        while(parent[temp] != temp) {
            // while we have not reached src itself.
            cout << temp << "<-";
            temp = parent[temp];
        }
        cout << src << endl;
        return dist[dest];
    }
};

int main() {
    Graph<int> g;
    
    // board conditions
    int board[50] = {0};
    // snakes or ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[17] = -13;
    board[18] = 11;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    // adding edges: unidirectional

    // each position and each die roll
    for(int i=0; i<37; i++) {
        for(int dice=1; dice<7; dice++) {
            int j = i + dice;
            j += board[j]; //adding board conditions. either snakes or ladders.

            // here none of the values for i=36 will be added.
            // meaning
            // i = 36, j = 1,2,3,4,5,6 are all greater than 36
            // meaning an edge from 36 to any other node doesnt exist.
            // the problem is: the node from 36 to itself also doesnt exist.
            // meaning the vertex 36 doesnt exist in the graph.
            // so we need to add it outside this loop.
            if(j<=36) {
                g.add_edge(i, j);
            }
        }
    }
    g.add_edge(36, 36);

    cout << g.shortest_path_bfs(0, 36);

    return 0;
}
