//NPhạm Văn Phong, 20215448, 738919
#include <stdio.h>
int main(){
	int x, y, z; // 3 biến x, y, z để lưu giá trị 3 số nguyên
	int *ptr;
	printf("Enter three integers: ");
	scanf("%d%d%d", &x, &y, &z); // nhập giá trị 3 số nguyên
	printf("\nThe three integers are:\n");
	
	// in ra giá trị 3 số đó bằng con trỏ
	ptr = &x;
	printf("x = %d\n", *ptr);
	ptr = &y;
	printf("y = %d\n", *ptr);
	ptr = &z;
	printf("z = %d\n", *ptr);
	return 0;
}