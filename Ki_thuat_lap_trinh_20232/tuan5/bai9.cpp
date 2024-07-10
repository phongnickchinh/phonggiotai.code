#include<iostream>

using namespace std;

struct block{
    int x, y, z;
    block(int x1 = 0, int y1 = 0, int z1 = 0){
        x = x1;
        y = y1;
        z = z1;
    }
};

block a[100];
int n;
int maxh[100];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        a[3 * i - 2] = block(x, y, z);
        a[3 * i - 1] = block(y, z, x);
        a[3 * i] = block(z, x, y);
    }
}

int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for(int j = 1; j <= 3 * n; j++)
        if ((a[i].x < a[j].x && a[i].y < a[j].y)  ||   (a[i].x < a[j].y && a[i].y < a[j].x))
            maxh[i] = max (maxh[i], a[i].z + dp(j));
    return maxh[i];
}
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    int cnt = 1;
    while(1){
        int res = 0;
        input();
        for(int i=0; i<100; ++i)
            maxh[i] = 0;
        for(int i = 1; i <= 3 * n; i++)
            res = max(res, dp(i));
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}