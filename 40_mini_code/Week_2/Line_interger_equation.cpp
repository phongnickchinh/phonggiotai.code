#include<bits/stdc++.h>
using namespace std;

int n, M;
vector<int> Elements;

void solution(){
     for (unsigned int i = 0; i < Elements.size(); i++) {
                cout << Elements[i]<< " ";
            }
            cout << endl;
}

void Try(int soluong, int Tong){
    //nếu hết chỗ và tổng còn lại bằng 0 thì ta thu được 1 kết quả:
    if(soluong==0){
        if(Tong==0) solution();
        return; //back track về nhánh trước
    }else{
        for (int i = 1; i <=Tong; i++){
            //lần lượt thêm các số vào vector, cho đến khi tổng còn lại bằng 0
            if(i<=Tong){
                Elements.push_back(i);
                Try(soluong-1,Tong-i); //gọi hàm với phần tử tiếp theo và phần tổng còn lại
                Elements.pop_back();
            }    
        }     
    }
    
}
int main(){
cin>>n>>M;
Try(n,M);
return 0;
}