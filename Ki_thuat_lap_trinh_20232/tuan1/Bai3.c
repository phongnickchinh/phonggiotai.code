//PHạm Văn Phong, 20215448, 738919
#include <stdio.h>
int main() {
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z); // nhập giá trị 3 biến
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z); // in ra giá trị 3 biến ban đầu
    
    //cộng mổi biến thêm 100 bằng con trỏ
    ptr = &x;
    *ptr += 100;
    ptr = &y;
    *ptr += 100;
    ptr = &z;
    *ptr += 100;
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z); // in ra giá trị 3 biến sau khi cộng thêm
    return 0;
}   
