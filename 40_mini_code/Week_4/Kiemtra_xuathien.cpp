#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    int number;
    vector<int> list; //dùng vector cho việc nhập vào dữ liệu
    map<int,vector<int>> appear_list; //dùng map kiểm tra thứ tự xuất hiện của giá trị
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>number;
        list.push_back(number);
    }

    for(int i=0;i<n;i++){
        appear_list[list[i]].push_back(i);
    }

    for(int i=0; i<n;i++){
        //nếu giá trí xuất hiện lần đầu trong bảng đánh dấu thì trả về không, nếu xuát hiện từ làn thứ hai trả về 1
        if(appear_list[list[i]][0]>=i) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;

}
