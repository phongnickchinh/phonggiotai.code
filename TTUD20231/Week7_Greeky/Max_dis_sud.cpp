#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("inut.txt", "r", stdin);
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());

        int maxDistance = 0;
        for (int i = 1; i < N; i++) {
            int distance = positions[i] - positions[i - 1];
            maxDistance = max(maxDistance, distance);
        }

        cout << maxDistance << endl;
    }

    return 0;
}
