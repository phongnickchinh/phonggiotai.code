#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
const int N = 128;

struct Matrix {
    unsigned int mat[N][N];

    Matrix() {
        memset(mat, 0, sizeof mat);
    }
};

bool operator == (const Matrix &a, const Matrix &b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j]) return false;
        }
    }
    return true;
}

// Hàm tính tích chậm.
Matrix multiply_naive(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

// Hàm tính tích nhanh.
Matrix multiply_fast(const Matrix &a, const Matrix &b) {
    Matrix c;
    unsigned int temp = 0; // Biến temp để lưu giá trị của một phần tử ma trận tích.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                temp += a.mat[i][k] * b.mat[k][j]; // Tính giá trị phần tử của ma trận tích tại hàng i cột j theo công thức.
            }
            c.mat[i][j] = temp;
            temp = 0;
        }
    }
    return c;
}

// Tạo ngẫu nhiên ma trận.
Matrix gen_random_matrix() {
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

// Tính hiệu suất.
double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix &result) {
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;

    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    base = gen_random_matrix();
    Matrix a, b;
    printf("Slow version\n");
    double slow = benchmark(multiply_naive, a);
    printf("Fast version\n");
    double fast = benchmark(multiply_fast, b);
    
    if (a == b) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}