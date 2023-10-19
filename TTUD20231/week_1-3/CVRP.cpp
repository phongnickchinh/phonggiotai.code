#include<bits/stdc++.h>
#define N 50
using namespace std;
int x[N];
int load;
bool visited[N];
int f_min=INT_MAX;
int f, n, K;
int c[50][50];
int c_min=INT_MAX;
void solution(){
    if(f+c[2*n+1][x[0]]<f_min){
        f_min=f+ c[x[2*n]][x[0]];
    }
}
bool check(int v, int k){
    if(visited[v]==true) return false;
    if(v<=n){
        if(load>=K) return false;
        if(visited[n+v]==true) return false;
    }else if(visited[v-n]==false) return false;
    return true;
}

void TRY( int k){
    for(int v=1; v<=2*n; v++){
        x[k]=v;
        visited[v]=true;
        f=f+c[x[k-1]][x[k]];
        if(v<=n) load+=1; else load-=1;
        if(k==2*n) solution();
        else if(f+cmin*(2n+1-k)<min) TRY(k+1);
    }
}

int main(){

    for(int v=1; v<=1*n; v++){
        visited[v]=false;
    }
    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    
    

}