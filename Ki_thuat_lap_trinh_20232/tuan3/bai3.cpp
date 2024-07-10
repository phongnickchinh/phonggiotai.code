/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# s? thành ph? và ma tr?n chi phí
int cmin = INT_MAX; //# chi phí di l?i nh? nh?t gi?a hai thành ph? khác nhau
int best = INT_MAX; //# t?ng chi phí nh? nh?t c?n tìm, ban d?u d?t b?ng giá tr? vô cùng l?n INT_MAX = 2^31-1
int curr = 0; //# t?ng chi phí t?i th?i di?m hi?n t?i
int mark[MAX]; //# dánh d?u nh?ng thành ph? dã di
int x[MAX]; //# luu gi? các thành ph? dã di
//int xmax[MAX];
//# Ð?c d? li?u vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thu?t toán quay lui
void TRY(int k){
	if(k == (n+1)){
//		x[k] = 1;
		curr += c[x[k-1]][1];
		if(curr < best){
			best = curr;
//			for(int i=1; i<=(n+1); i++)
//   				xmax[i] = x[i];
    	}
    	curr -= c[x[k-1]][1];
		return;
	}
    for(int i = 2; i <= n; i++){
    	int t = 0;
		for(int j=1; j<k; j++)
			if(x[j] == i){
				t = 1;
				break;
			}
		if(t == 1)
    		continue;
    	t = c[x[k-1]][i];
    	if(t > 0){
    		curr += t;
    		x[k] = i;
    		TRY(k+1);
    		curr -= t;
		}
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;    		
//	for(int i=1; i<=(n+1); i++)
//   		cout << xmax[i] << " ";
    return 0;
}