#include <iostream>

using namespace std;

// Lập phương số nguyên
int cube(int x){
    return x*x*x;
}

// Lập phương số thực
double cube(double x){
	return x*x*x;	
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f); // nhập số nguyên và số thực
    
    // In ra giá trị lập phương số nguyên và số thực
    printf("Int: %d\n", cube(n)); 
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}