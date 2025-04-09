#include<bits/stdc++.h>
#define MAX_N 1000001

using namespace std;
int n, M, H,  list_trees[MAX_N], highest_tree=-1;


bool check(int h){
    int sum=0;
    for(int i=0; i<n; i++ ){
        sum+=max(0, list_trees[i]-h);
    }

    return sum>=M;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>M;

    for(int i=0; i<n; i++){
        cin>>list_trees[i];
        highest_tree=max(highest_tree, list_trees[i]);
    }

    int low = 0, high=highest_tree, mid, result=0;

    while(low<=high){
        // cout<<"hehhee";
        mid = (low+high)/2;
        if(check(mid)){
            result=mid;
            low=mid+1;
        }
        else high = mid-1;
    }

    cout<<result;
    return 0;

}