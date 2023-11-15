#include <iostream>
#include <vector>
#include <climits>

struct Node {
    int v, c;
    Node *next, *rev;
    Node(int v1, int c1, Node *next1) : v(v1), c(c1), next(next1), rev(nullptr) {}
};

const int MAX_N = 40001;
Node *graph[MAX_N];
Node *path[MAX_N];
bool visited[MAX_N];
int n, m, s, t, maxFlow = 0, p = 1;

void augmentPath(int flow) {
    for (int i = 1; i < p; ++i) {
        path[i]->c -= flow;
        path[i]->rev->c += flow;
    }
    maxFlow += flow;
}

void dfs(int u) {
    if (u == t) {
        int flow = INT_MAX;
        for (int i = 1; i < p; ++i)
            flow = std::min(flow, path[i]->c);
        augmentPath(flow);
        return;
    }
    Node *temp = graph[u];
    while (temp) {
        if (!visited[temp->v] && temp->c) {
            path[p++] = temp;
            visited[temp->v] = true;
            dfs(temp->v);
            visited[temp->v] = false;
            p--;
        }
        temp = temp->next;
    }
}

int main() {
    std::cin >> n >> m >> s >> t;
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph[u] = new Node(v, c, graph[u]);
        graph[v] = new Node(u, 0, graph[v]);
        graph[u]->rev = graph[v];
        graph[v]->rev = graph[u];
    }
    visited[s] = true;
    dfs(s);
    std::cout << maxFlow;
    return 0;
}
