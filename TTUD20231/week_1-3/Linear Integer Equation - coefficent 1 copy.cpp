#include<bits/stdc++.h>
using namespace std;

int n, M;//số phần tử và tổng của phương trình
vector<int> coefficient; //hệ số của phương trình

void solution(const vector<int>& Phantu) {
    for (unsigned int i = 0; i < Phantu.size(); i++) {
        cout << Phantu[i] << " "; //in ra 1 nghiệm
    }
    cout << endl;
}

//soluong: số lượng phần tử còn lại
//Tong: tổng còn lại
//Phantu: vector chứa các phần tử của một nghiệm đã chọn
//heso: vector chứa hệ số của phương trình
void Try(int soluong, int Tong, vector<int> Phantu,vector<int> heso) {
    if (soluong == 0) {
        if (Tong == 0) {
            solution(Phantu);
        }
        return;
    } else {
        for (int i = 1; i <= Tong; i++) {
            Phantu.push_back(i);
            Try(soluong - 1, Tong - i*heso[n-soluong], Phantu, heso);//đệ quy giảm số lượng và giảm tổng
            Phantu.pop_back();//quay lui
        }
    }
}

int main() {
    cin >> n >> M;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        coefficient.push_back(x);
    }
    Try(n, M,{},coefficient);
    return 0;
}
