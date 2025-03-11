#include<bits/stdc++.h>

using namespace std;
#define MAX_N 20
int n, min_distance=99999, total_distance=0;
int visited[2*MAX_N+1], result[2*MAX_N+1];
int phong[2*MAX_N+1][2*MAX_N+1];


int check(int i){
    return !visited[i];
}

void solution(){
    // printf("%d\n", total_distance);
    total_distance+=phong[n+result[n]][0];
    // printf("%d\n", total_distance);
    min_distance = min(min_distance, total_distance);
    // printf("%d\n", min_distance);
    total_distance-=phong[n+result[n]][0];
}

void Try(int k){
    if(k==(n+1)) {
        solution();
        return;
    }
    for(int i=1; i<=n; i++){
        if(check(i)){
            visited[i] = 1;
            result[k]=i;
            if(k==1) total_distance=phong[0][result[1]]+phong[result[1]][n+result[1]];
            else{
                total_distance+= phong[n+result[k-1]][result[k]]+phong[result[k]][n+result[k]];
            }

            if(total_distance<min_distance) Try(k+1);

            if(k==1) total_distance=0;
            else{
                total_distance-= phong[n+result[k-1]][result[k]]+phong[result[k]][n+result[k]];
            }
            visited[i]=0;

        }
    }

}

int main() {
    scanf("%d", &n);

    for (int i = 0; i <= 2*n; i++) {
        visited[i] = 0;
        for (int j = 0; j <= 2*n; j++) {
            scanf("%d", &phong[i][j]);
        }
    }

    result[0] = 0;
    visited[0] = 1;
    Try(1);
    printf("%d", min_distance);
    // for(int i=0; i<=n; i++){
    //     printf("%d ", result[i]);
    // }
    return 0;
}