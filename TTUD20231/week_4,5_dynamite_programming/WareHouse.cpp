#include<bits/stdc++.h>
using namespace std;

int save[1001][101];
int Solution(int n, int T, int D, int time[], int weight[]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= T; j++) {
            if (j >= time[i] && j - time[i] <= D) {
                save[i][j] = max(save[i - 1][j - time[i]] + weight[i], save[i - 1][j]);
            } else {
                save[i][j] = save[i - 1][j];
            }
        }
    }
    return save[n][T];
}

int main() {
    int weight[1001], time[1001];
    int n, T, D, result = 0;
    cin >> n >> T >> D;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 101; j++) {
            save[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &time[i]);
    }
    int temp = Solution(n, T, D, time, weight);
    cout << temp;
    return 0;
}
