


#include <bits/stdc++.h>
using namespace std;


bool next_permutation(vector<int> &a) {
    int n = a.size();
    int i = n - 2;

    // B1: Tìm phần tử a[i] sao cho a[i] < a[i + 1]
    while (i >= 0 && a[i] >= a[i + 1]) i--;

    // Nếu không tìm được => đây là hoán vị cuối cùng
    if (i < 0) return false;

    // B2: Tìm phần tử a[j] nhỏ nhất > a[i] từ cuối dãy
    int j = n - 1;
    while (a[j] <= a[i]) j--;

    // B3: Đổi chỗ a[i] và a[j]
    swap(a[i], a[j]);

    // B4: Đảo ngược đoạn từ a[i+1] đến hết
    reverse(a.begin() + i + 1, a.end());

    return true;
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;

    do {
        for (int x : a) cout << x << " ";
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
