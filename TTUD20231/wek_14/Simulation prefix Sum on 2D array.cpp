//tông ôvuông

#include<bits/stdc++.h>
using namespace std;

int main(){
   //freopen("test.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    //tính tổng tiền tố
    vector<vector<int>> sum(n+1,vector<int>(m+1));
    sum[0][0]=0;
    for(int i=1;i<=n;i++){
        sum[i][0]=0;
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }

    //đọc m cặp số nguyên r1,c1,r2,c2
    int k;
    cin>>k;
    int r1,c1,r2,c2;
    for(int i=0;i<k;i++){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        printf("%d\n",sum[r2][c2]-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1]);
    }
    return 0;

}
