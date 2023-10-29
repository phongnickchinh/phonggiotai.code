//Phạm Văn Phong 20215448_29/10/2023
#include<bits/stdc++.h>
using namespace std;
// Nhập vào số đồ thị, số đỉnh, số cạnh và danh sách cạnh
// Chương trình tính toán xem có phải là đồ thị hamilton không?
// sử dụng Định lí Dirak: https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_Dirac

int main(){
    
    int graph, node, egde, p=0;
    vector<int> appear(node+1);
   
    vector<int> result(graph,1);
    
    cin>>graph;
    while(p<graph){
        cin>>node>>egde;
        int n,m;
        for(int i=1;i<=egde; i++){
            scanf("%d%d", &n, &m);
            appear[n]++;
            appear[m]++;
        }
        for(int i=1; i<=node; i++){
            if(appear[i]<(node/2)){
                result[p]=0;
                break;
            }
        }
        p++;
    }
    for (auto &&number : result) printf("%d\n", number);
    return 0;
    
    

}