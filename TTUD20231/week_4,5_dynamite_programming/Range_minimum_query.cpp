#include <bits/stdc++.h>
using namespace std;

#define N 1000000

void preprocessing(int n, vector<int>& input, vector<vector<int>>& save) {
    int index = log2(n);

    for (int i = 0; i < n; i++) {
        save[0][i] = input[i];
    }

    for (int i = 1; i <= index; i++) {
        for (int j = 0; j < n; j++) {
            if (save[i - 1][j + (1 << i) - 1] == -1) {
                save[i][j] = save[i - 1][j];
            } else {
                if (save[i - 1][j] <= save[i - 1][j + (1 << (i - 1)) - 1]) {
                    save[i][j] = save[i - 1][j];
                } else {
                    save[i][j] = save[i - 1][j + (1 << (i - 1)) - 1];
                }
            }
        }
    }
}

int findmin(int a, int b, vector<vector<int>>& save) {
    int index = log2(b - a);
    int solution = 0;

    if (save[index][a] <= save[index][b - (1 << index) + 1]) {
        solution = save[index][a];
    } else {
        solution = save[index][b - (1 << index) + 1];
    }

    return solution;
}

int main() {
    int n, m, total = 0;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    vector<vector<int>> save(30, vector<int>(N));

    preprocessing(n, list, save);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        total += findmin(a, b, save);
    }

    cout << total;

    return 0;
}
