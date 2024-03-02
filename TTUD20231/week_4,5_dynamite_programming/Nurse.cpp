#include<bits/stdc++.h>
using namespace std;
#define  m (int)(1e9+7)
int solution(int n, int k1, int k2){
vector<int> solution_1(n+1);
vector<int> solution_0(n+1);

for(int i=1; i<k1;i++) solution_1[i]=0;
solution_1[k1]=1;
for(int i=k1+1;i<=k2;i++) solution_1[i]=2;

solution_0[1]=1;
solution_0[k1+1]=1;
for(int i=k1+2;i<=k2; i++) solution_0[i]=2;
for(int i=2; i<k1+1;i++) solution_0[i]=0;
for(int i=k2+1; i<=n;i++){
    for(int j=i-k2;j<=i-k1; j++) solution_1[i]+=solution_0[j];
    solution_0[i]=solution_1[i-1];
}
return (solution_0[n]+solution_1[n]);
}
int main(){
    int n,  k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    cout<<solution(n, k1, k2);
    return 0;
}
