#include <bits/stdc++.h>
using namespace std;
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}