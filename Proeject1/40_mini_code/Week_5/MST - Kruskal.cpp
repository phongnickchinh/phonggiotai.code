//Phạm Văn Phong 20215448_29/10/2023
#include <bits/stdc++.h>
using namespace std;
//sử dụng cấu trúc dữ liệu Disjoin Set Union, là một tập hợp gồm các nút có nút cha
//và độ cao của tập hợp tính tới nút đó
class DSU {
    int *parent;
    int *rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1; //các tập hợp chỉ 1 phần tử không có cha
            rank[i] = 1;
        }
    }

    //Phương thức trả về nút cao nhất trong tập hợp (nút tổ tiên)
    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    //phương thức gộp 2 tập hợp riêng lẻ
    //Không gộp 2 tập hợp cùng tổ tiên tránh tạo ra chu trình
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

//Biểu thị đồ thị bao gồm danh sách cạnh và số đỉnh:
class Graph {
    vector<vector<int>> edgelist;
    int V;

public:
    //tạo một đồ thị với số cạnh V và danh sách cạnh rỗng:
    Graph(int V) { this->V = V; }
    //thêm cạnh đỉnh u, v trọng số w vào đồ thị:
    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }
    //thuật toán Kruskal tìm cây khung nhỏ nhất
    //bằng cách gộp các cạnh dưới dạng các tập hợp DSU thành một tập hợp lớn hơn:
    void kruskals_mst() {
        //sắp xếp danh sách cạnh theo chiều tăng dần trọng số cạnh
        sort(edgelist.begin(), edgelist.end()); 
        DSU s(V); //khởi tạo các tập hợp cơ sở gồm 1 phần tử
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            //kiểm tra liệu 2 nút x và y có cùng nút tổ tiên không
            //nếu không, gộp cạnh này vào cây khung cần tìm:
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        cout << ans;
    }
};

int main() {
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
