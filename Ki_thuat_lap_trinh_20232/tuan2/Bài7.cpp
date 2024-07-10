#include <iostream>
using namespace std;

template <typename T> // định kiểu cho kiểu dữ liệu là T
T arr_sum(T *a, int n1, T *b, int n2){
    T sum = 0;
	for(int i=0; i<n1; i++){
    	sum += *(a+i); // tính tổng mảng 1
	}
	for(int i=0; i<n2; i++){
    	sum += *(b+i); // tính tổng 2 mảng
	}
	return sum;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    int val;
    cin >> val; // nhập giá trị val
    
    {   // Tạo 2 mảng số nguyên và tính tổng
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {   // Tạo 2 mảng số thực và tính tổng
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}