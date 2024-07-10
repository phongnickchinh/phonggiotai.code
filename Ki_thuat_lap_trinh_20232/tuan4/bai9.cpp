#include <iostream>
#include <queue>
#include <climits>
using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    vector<int> d(adj.size());
    vector<bool> v(adj.size());
    d[0] = 0; v[0] = false;
    for(int i = 1; i < (int) adj.size(); ++i){
        d[i] = 1000000;
        v[i] = true;
    }
    int p = 0, di = 0, m;
    for(int i = 0; i < (int) adj.size(); ++i){
        m = 1000000;
        for(auto j = adj[p].begin(); j != adj[p].end(); ++j)
            if(v[j->first])
                d[j->first] = min(d[j->first],  di + j->second);
        
        for(int j = 0; j < (int) d.size(); ++j)
            if(v[j] && (d[j] < m)){
                    m = d[j];
                    p = j;
            }
        
        di = m;
        v[p] = false;
    }
    return d;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}