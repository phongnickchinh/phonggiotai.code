/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    Vector cp = { get<1>(a) * get<2>(b) - get<1>(b) * get<2>(a),
                get<2>(a) * get<0>(b) - get<2>(b) * get<0>(a),
                get<0>(a) * get <1>(b) - get<0>(b) * get<1>(a)};
    return cp;
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    // cout << get<0>(a);
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}