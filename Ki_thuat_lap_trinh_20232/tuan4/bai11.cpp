#include<iostream>
#include<algorithm>

using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    // file test 11 chua test case 4
    freopen("test11.txt", "r", stdin);
    int n, s, a, b=0, i;
    cin >> n >> s;
    pair<int, int> ka[n];
    
    for(i=0; i<n; ++i){
        cin >> ka[i].second; //so ten giac tan cong
        cin >> ka[i].first; // linh chong duoc bao ten
        if(ka[i].first > ka[i].second)
            ka[i].first = ka[i].second;
    }

    sort(ka, ka + n);
    i = n;
    while(s > 0){
        if(ka[--i].first < b){
            sort(ka, ka + n);
            i = n;
            b = 0;
        }
        else{
            a = ka[i].second / ka[i].first;
            if(s>a)
                s -= a;
            else{
                a = s;
                s = 0;
            }
            ka[i].second -= a * ka[i].first;
            ka[i].first = ka[i].second;
            b = min(b, ka[i].first);
        }
    }

    int count = 0;
    for(i=0; i<n; ++i)
        count += ka[i].second;
    cout << count;
}