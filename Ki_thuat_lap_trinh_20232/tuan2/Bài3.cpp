#include <stdio.h>

int get_value(int x, int a=2, int b=1, int c=0){
	return a*x*x + b*x + c;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    int x;
    scanf("%d", &x);
    
    int a = 2; // giá trị mặc định a
    int b = 1; // giá trị mặc định b
    int c = 0; // giá trị mặc định c
    
    scanf("%d%d%d", &a, &b, &c); // Nhập a, b, c
    
    // Lần lượt in ra với số lượng đầu vào thay đổi, giá trị không được nhập vào sẽ nhận giá trị mặc định 
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}