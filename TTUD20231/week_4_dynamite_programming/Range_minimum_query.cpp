#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int save[30][1000000];


void preprocessing(int n, vector<int> input, int save[30][1000000]){
    int index=(int)log2(n);

    for(int i=0; i<n;i++) save[0][i]=input[i];

    for(int i=1;i<=index; i++){
        for(int j=0; j<n; j++){
            if(save[i-1][j+(int)pow(2,i)-1]==-1) save[i][j]=save[i-1][j];
            else {
                if(save[i-1][j]<=save[i-1][j+(int)pow(2,i-1)-1]) save[i][j]=save[i-1][j];
                else save[i][j]=save[i-1][j+(int)pow(2,i-1)-1];
                }
        }
    }
}

int findmin(int a, int b){
    int index=(int)log2(b-a);
    int solution=0;

    if(save[index][a]<=save[index][b-(int)pow(2,index)+1]) solution=save[index][a];
    else  solution= save[index][b-(int)pow(2,index)+1];
    return solution;
}

int main(){
    int n,m,total=0;
    cin>>n;
    vector<int> list(n);
     
    for(int i=0; i<=N; i++){
        for(int j=0; j<30;j++){
            save[j][i]=-1;
        }
    }
    for(int i=0; i<n;i++){
        scanf("%d", &list[i]);
    }
    preprocessing(n,list,save);

    cin>>m;
    for(int i=0; i<m;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        total+=findmin(a,b);

    }cout<<total;




}
