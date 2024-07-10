#include<bits/stdc++.h>
using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/
int x[2000000] = {};
int main(){
    // freopen("inp.txt", "r", stdin);    
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    int l = s.length() + 1, count = 0, temp = 1000000;
    while(l--){
        if(s[l] == '1') temp += 1;
        else temp -= 1;
        x[temp] += 1;
    }
    for(int i = 0; i < 2000000; ++i)
        count += x[i] * (x[i] - 1) / 2;
    cout << count;
}