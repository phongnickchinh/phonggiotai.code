#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long powerMod(long long base, long long exponent) {
    long long result = 1;
    base = base % MOD;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }

    return result;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long result = powerMod(a % MOD, b);
    cout << result << endl;

    return 0;
}
