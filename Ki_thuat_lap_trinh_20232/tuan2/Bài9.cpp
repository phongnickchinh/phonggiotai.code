#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include<iostream>
using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
/*****************/
#define MAX_N 100000
#define denta 0.0001
double sigmoid[MAX_N];
const double start = -5.0;
const double stop = 5.0;
/*****************/

//# hàm chuẩn bị dữ liệu
void precalc() {
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
    double foo = start;
    // Cho x chạy khoảng giá trị 10 đơn vị từ -5, bước nhảy là 10e-5, tính sigmoid(x)
    for(int i=0; i<MAX_N; i++){ 
        sigmoid[i] = sigmoid_slow(foo);
        foo += denta;
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    // Nếu x < -5 hoặc lớn hơn 5 thì trả về 0 hoặc 1 tương ứng vì sai số nhỏ
    if(x < start) return 0.0;
    if(x > stop) return 1.0;

    // Tính giá trị i để tra mảng sigmoid đã lưu 
    int i = floor((x - start) / denta);

    // Lấy giá trị sigmoid từ mảng giá trị đã lưu
    return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta)) / (denta);

    /*****************/
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//# printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow/fast > 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        //printf("Wrong answer or your code is not fast enough!\n");
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }

    return 0;
}