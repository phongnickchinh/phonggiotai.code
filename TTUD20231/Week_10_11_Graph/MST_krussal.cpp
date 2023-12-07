#include <bits/stdc++.h>
using namespace std;

//đây là cấu trúc dữ liệu Disjoint Set Union
//Cấu trúc này bao gồm các phần tử có thể gộp nhóm với nhau
//parent[i] là cha của phần tử i
//rank[i] là độ cao của cây gốc i
//Nếu 2 phần tử thuộc 2 tập hợp khác nhau thì gộp 2 tập hợp đó lại
//Nếu 2 phần tử thuộc cùng 1 tập hợp thì bỏ qua
class DSU {
    int *parent;
    int *rank;

public:
    // Khởi tạo mảng parent và rank 
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // pt Tìm tập hợp chứa phần tử i
    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    //pt Gộp 2 tập hợp chứa x và y
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }

    //TÌM CÂY  khung nhỏ nhất bằng thuật toán Kruskal
    //Sắp xếp các cạnh theo thứ tự tăng dần
    //Duyệt qua các cạnh, nếu 2 đỉnh của cạnh đó không thuộc cùng 1 tập hợp thì thêm cạnh đó vào cây khung
    //Nếu 2 đỉnh của cạnh đó thuộc cùng 1 tập hợp thì bỏ qua cạnh đó
    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        cout << ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.kruskals_mst();
    return 0;
}
