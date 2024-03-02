#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    long long inversions = 0;

    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += n1 - i;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    return inversions;
}

long long mergeSortAndCount(vector<int>& arr, int n) {

    long long inversions = 0;
    int curr_size;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            inversions += mergeAndCount(arr, left_start, mid, right_end);
        }
    }

    return inversions;
}

int main() {
        freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = mergeSortAndCount(arr, n);

    cout << result % 1000000007 << endl;

    return 0;
}
