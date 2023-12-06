#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000001];
vector<bool> visited;

void DFS(int source) {
    stack<int> st;
    st.push(source);
    visited[source] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    freopen("test1.txt", "r", stdin);
    cin >> n >> m;
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(i);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}
