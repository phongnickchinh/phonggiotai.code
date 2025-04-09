#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);       // Lưu hoán vị tại mỗi cấp
    vector<bool> used(n + 1, false); // Đánh dấu số đã dùng
    int k = 1;

    while (k > 0) {
        a[k]++;
        while (a[k] <= n && used[a[k]]) {
            a[k]++;
        }

        if (a[k] <= n) {
            used[a[k]] = true;

            if (k == n) {
                // In ra hoán vị
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << endl;

                used[a[k]] = false; // backtrack
            } else {
                k++;
                a[k] = 0;
            }
        } else {
            k--; // Quay lui
            if (k > 0) used[a[k]] = false;
        }
    }

    return 0;
}
