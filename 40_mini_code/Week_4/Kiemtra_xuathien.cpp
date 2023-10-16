#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    int number;
    vector<int> list;
    map<int,vector<int>> appear_list;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>number;
        list.push_back(number);
    }
        //giờ tôi đang học lịch sử Đảng các bạn ạ
    for(int i=0;i<n;i++){
        appear_list[list[i]].push_back(i);
    }

    for(int i=0; i<n;i++){
        if(appear_list[list[i]][0]>=i) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;

}