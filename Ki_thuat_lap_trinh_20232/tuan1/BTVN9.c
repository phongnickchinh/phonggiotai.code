#include<stdio.h>
//Phạm Văn Phong, 20215448, 738919
int main(){
	int n;
	scanf("%d", &n);
	int s[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	for(int i = 0; i < n ; i++){
		for(int k = i+1; k <= n; k++){
			for(int j = i; j < k; j++)
				printf("%d ", s[j]);
			printf("\n");
		}
	}
}
	