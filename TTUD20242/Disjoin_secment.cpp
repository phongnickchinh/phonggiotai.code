//sử dụng tham lam để giải quyết bài toán, sắp xếp các đoạn theo thứ tự không giảm của điểm cuối.
//điều kiện chọn: phải hoàn toàn không trùng điểm đầu của đoạn đang xét với điểm cuối của đoạn kết quả đang có last<list[i].start
#include<bits/stdc++.h>
using namespace std;


struct Disjoin_secment
{
    int start, end;

    Disjoin_secment(int s, int e){
        start= s;
        end= e;
    }
};


int main(){
    // freopen("input.txt", "r", stdin);
    vector<Disjoin_secment> list;
    int n, temp1, temp2;
    int count = 1, last;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin >> temp1 >> temp2;
        list.emplace_back(temp1, temp2);
    }

    sort(list.begin(),
        list.end(),
        [](const Disjoin_secment &a, const Disjoin_secment &b){return a.end<b.end;}
    );

    last=list[0].end;
    for(unsigned int i=1; i<list.size(); i++){
        if(last<list[i].start){
            count++;
            last=list[i].end;
        }
    }

    cout<<count;
    return 0;
}