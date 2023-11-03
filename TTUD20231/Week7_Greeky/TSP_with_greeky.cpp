#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // các vecto lưu trữ khoảng cách, thanh phố đã được thăm
    vector<vector<int>> distance(n, vector<int>(n));
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &distance[i][j]);
        }
    }
    //
    vector<int> result;
    int current = 0;
    result.push_back(current + 1);
    visited[current] = 1;

    //Kết thúc khi duyệt hết các đỉnh
    for (int i = 0; i < n - 1; i++) {
        int next = -1;
        int min_distance = INT_MAX;

        //Duyệt tìm điểm đế tiếp theo gần nhất:
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance[current][j] < min_distance) {
                min_distance = distance[current][j];
                next = j;
            }
        }
        if (next == -1) {
            break; //Đã đi hết các thành phố
        }
        result.push_back(next + 1);
        visited[next] = 1;
        current = next;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
