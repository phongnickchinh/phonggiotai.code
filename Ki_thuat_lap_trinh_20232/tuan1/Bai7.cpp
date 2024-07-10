// Phạm Văn Phong, 20215448, 738919

#include<iostream>

using namespace std;

int main(){
	int *a, n, tmp, k;                          // a là con trỏ quản lý mảng
	printf("Enter the number of elements: ");
	scanf("%d", &n);                            // nhập số lượng phần tử
	a = new int[n];                             // cấp phát bộ nhớ
	for(int i = 0; i < n; i++)
		scanf("%d", (a + i));                   // nhập các phần tử
	printf("The input array is: \n");
	for(int i = 0; i < n; i++)
		printf("%d ", *(a + i));
	printf("\n");
	for(int i = 0; i < n; i++){                 // sắp xếp chọn
		k = i;
		for(int j = i + 1; j < n; j++)
			if(*(a+j) < *(a+k))
				k = j;
		tmp = *(a+i);
		*(a+i) = *(a+k);
		*(a+k) = tmp;
	}
	printf("The sorted array is: \n");
	for(int i = 0; i <n; i++)
		printf("%d ", *(a + i));                // in ra giá trị sau khi sắp xếp
	printf("\n");
	delete []a;
	return 0;
}