//Sum pair of sequence equal to a number
#include<bits/stdc++.h>
using namespace std;


int main(){
    map<int,int> list; //sử dụng map truy cập cho nhanh, đỡ phải dùng vòng lặp lồng nhau
    int n,m;
    int value;
    cin>>n>>m;
    int count=0;
    for(int i=0; i<n; i++){
        cin>>value;
        list[value]=value; //giá trí được đặt làm key luôn, để tí dùng cả key của value

    }
    for( auto &number: list){
        //tổng =number + 1 số khác, tìm kiếm cái số khác này nếu tồn tại trong map thì count ++
        if(list.find(m-number.second)!=list.end()){
            if(number.second!=(double)m/2)count++;// cần loại đi trường hợp number= tổng/2
        }
    }
    count/=2;
    cout<<count;
    return 0;
}
