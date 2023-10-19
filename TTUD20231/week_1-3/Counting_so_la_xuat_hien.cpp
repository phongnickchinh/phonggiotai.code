#include <iostream>
#include <vector>
using namespace std;

int main() {
    const unsigned long N = 1000000000;
    vector<unsigned long> cout_list(N, 0); // Kh?i t?o t?t c? d?m b?ng 0
    unsigned long n;
    cin >> n;
    vector<unsigned long> list(n);
    
    for (unsigned long i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    for (unsigned long i = 0; i < n; i++) {
        cout_list[list[i]] += 1;
        if (cout_list[list[i]] > 1) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}
