#include<bits/stdc++.h>
using namespace std;
//sử dụng các biến để lưu giá trị nhỏ nhất
//và lớn nhất của tổng các dãy con bắt đầu từ phần tử đầu tiên
// giá trị tổng dãy lớn nhất cần tìm là hiệu của max-min
int main(){
    int n, number_i;
    cin>>n;
    vector<int>sum_array(n+1);
    int min_total=sum_array[0];
    int max_total=sum_array[0];
    for(int i=1; i<n+1; i++){
        scanf("%d", &number_i);
        //cộng thêm phần tử vừa nhập vào tổng:
        sum_array[i]=sum_array[i-1]+number_i;
        //cập nhật các giá trị min max:
        min_total=min(min_total, sum_array[i]);
        max_total=max(max_total, sum_array[i]);
    }
    cout<<max_total-min_total;
    return 0;
}