#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> duration(n + 1);
    vector<int> inDegree(n + 1, 0);//inDegree[i] là bậc vào của đỉnh i
    vector<vector<int>> adjList(n + 1);//adjList[i] là danh sách các đỉnh kề với đỉnh i

    for (int i = 1; i <= n; ++i) {
        cin >> duration[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> earliestCompletionTime(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);  
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            earliestCompletionTime[neighbor] = max(earliestCompletionTime[neighbor], earliestCompletionTime[current] + duration[current]);

            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    int result = *max_element(earliestCompletionTime.begin(), earliestCompletionTime.end());

    cout << result << endl;

    return 0;
}
