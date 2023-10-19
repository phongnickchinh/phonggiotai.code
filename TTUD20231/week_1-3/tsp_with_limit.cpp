    #include<bits/stdc++.h>
    using namespace std;
    #define N 50
    int cost[50][50], result[N];
    int n,m, total_distance=0, last_solution=0;

    bool Havent_appear(int k, int v){
        for(int i=0; i<k;i++){
            if(result[i]==v) return false;
        }return true;
    }

    void solution(){
        total_distance+=cost[result[n-1]][result[0]];
/*       for (int i = 0; i < n; i++)
        {
            cout<<result[i];
        }
        
        cout<<endl;*/ 
        if(total_distance<=m) last_solution++;
    }

    void find_solution(int vitri){
        if(vitri>n-1){
            solution();
            return;
        }
        for(int i=1;i<=n;i++){
            if(Havent_appear(vitri,i)){
                result[vitri]=i;
                total_distance+=cost[result[vitri-1]][result[vitri]];
                if(total_distance<=m) {
                    find_solution(vitri+1);
                    total_distance-=cost[result[vitri-1]][result[vitri]]+cost[result[n-1]][result[0]];
                    result[vitri]=0;
                }else{
                    total_distance-=cost[result[vitri-1]][result[vitri]];
                    result[vitri]=0;
                    
                }
                
            }


            
        }
    }
    int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>cost[i][j];
        }
    }
    result[0]=1;

    find_solution(1);
    cout<<last_solution;

    }
