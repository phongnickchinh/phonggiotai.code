#include<iostream>

void allocate_mem(int ***mt, int m, int n){
	*mt = new int*[m];                          // cấp phát bộ nhớ
	for(int i = 0; i < m; i++)
		(*mt)[i] = new int[n];
}

void input(int **mt, int m, int n){
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++){
			printf("mt[%d][%d] = ", i, j);
			scanf("%d", &mt[i][j]);             // nhập giá trị các phần tử ma trận
		}	
}

void output(int **mt, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", mt[i][j]);            // in ra ma trận
		printf("\n");
	}
}

int process(int **mt, int m, int n){
	int tong = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(mt[i][j]%2 == 0)                 // nếu phần tử chia hết cho 2
				tong += mt[i][j];               // cộng tổng thêm phần tử đó
	return tong;
}

void free_mem(int **mt, int m, int n){
    for(int i = 0; i < m; i++){
        delete []mt[i];                         // giải phóng các mảng 1 chiều trước
    }
	delete []mt;                                // giải phóng ma trận
}
//NPhạm Văn Phong, 20215448, 738919
int main(){
	int m, n, **mt;
	printf("Enter m, n = ");
	scanf("%d%d", &m, &n);                      // nhập n
	
	allocate_mem(&mt, m, n);                    // tạo ma trận
	input(mt, m, n);                            // nhập ma trận
	output(mt, m, n);                           // in ma trận
	printf("The sum of all even elements is %d", process(mt, m, n));
	free_mem(mt, m, n);                         // giải phóng bộ nhớ
	return 0;
}