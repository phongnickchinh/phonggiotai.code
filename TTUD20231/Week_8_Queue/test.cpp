#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, r, c;
int maze[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

bool isValid(int x, int y) {
    //trả về true nếu
    return x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == 0 && !visited[x][y];
}

int bfs() {
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = p.first + dx[i];
            int newY = p.second + dy[i];

            if (isValid(newX, newY)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                maze[newX][newY] = maze[p.first][p.second] + 1;

                if (newX == 0 || newY == 0 || newX == n-1 || newY == m-1) {
                    return maze[newX][newY];
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    q.push({r-1, c-1});
    visited[r-1][c-1] = true;

    cout << bfs() << endl;

    return 0;
}

/*Input:
5 5 2 2
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

Output:
4*/