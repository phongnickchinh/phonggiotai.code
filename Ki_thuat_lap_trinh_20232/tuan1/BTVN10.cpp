// Phạm Văn Phong, 20215448, 738919

#include <bits/stdc++.h>
int n;

void allocate_mem(int ***mt){
	*mt = new int*[n];
	for(int i = 0; i < n; i++)
		(*mt)[i] = new int[n];
}

void input(int **mt){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &mt[i][j]);
}

void output(int **mt){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", mt[i][j]);
		printf("\n");
	}
}

void add(int **mt1, int **mt2, int ***tong){
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			(*tong)[i][j] = mt1[i][j] + mt2[i][j];
}

void mul(int **mt1, int **mt2, int ***tich){
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
            (*tich)[i][j] = 0;
            for(int k = 0; k < n; k++)
                (*tich)[i][j] += mt1[i][k] * mt2[k][j];
        }
}

void free_mem(int **mt){
    for(int i = 0; i < n; i++)
        delete []mt[i];
	delete []mt;
}

int main(){
	int **mt1, **mt2, **tong, **tich;
	scanf("%d", &n);
	allocate_mem(&mt1);
	allocate_mem(&mt2);
	allocate_mem(&tong);
	allocate_mem(&tich);
	input(mt1);
    input(mt2);
    add(mt1, mt2, &tong);
    mul(mt1, mt2, &tich);
	output(tong);
    output(tich);
    free_mem(mt1);
    free_mem(mt2);
    free_mem(tong);
    free_mem(tich);
	return 0;
}