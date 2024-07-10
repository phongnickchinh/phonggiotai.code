#include <stdio.h>
#include <math.h>

// Hàm lấy giá trị x, y và trả về căn bậc 2 của x*x + y*y
float get_hypotenuse(float x, float y) {
	float z = pow(x,2) + pow(y,2);
    z = (float) pow(z, (float)1/2);
    return z;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    float x, y;
    scanf("%f%f", &x, &y); // Nhập x, y
    
    float z = get_hypotenuse(x, y); // Gọi hàm tính.
    printf("z = %.2f\n", z); // in ra giá trị z.
    
    return 0;
}