#include<bits/stdc++.h>

using namespace std;

//liệt kê bằng thuật toán sinh.
string toBinary(int value, int length) {
    string res = "";
    while (value > 0) {
        res = char('0' + (value % 2)) + res;
        value /= 2;
    }
    // Bổ sung số 0 ở đầu nếu chưa đủ độ dài
    while ((int)res.size() < length) res = "0" + res;
    return res;
}

int main(){
    int n, temp=0;
    cin>>n;
    int hehe= (int) pow(2,n);
    for(int i=0; i<hehe; i++){
        cout<<toBinary(temp,n)<<endl;
        temp++;
    }
    return 0;
}