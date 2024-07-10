#include <bits/stdc++.h>
using namespace std;
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int cal(double a){
    if (a < 4.0) return 4;
    else if (a < 5.5) return 3;
    else if (a < 7.0) return 2;
    else if (a < 8.5) return 1;
    else return 0;
}

int main(){
    int n, s[5] = {};
    double a;
    cin >> n;
    while(n--){
        cin >> a;
        ++s[cal(a)];
    }
    cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4];
}