#include<bits/stdc++.h>
using namespace std;

//sử dụng các biến để lưu giá trị nhỏ nhất
//và lớn nhất của tổng các dãy con bắt đầu từ phần tử đầu tiên
// giá trị tổng dãy lớn nhất cần tìm là hiệu của max-min
//vì là tổng chẵn nên phải là chẵn-chẵn hoặc lẻ-lẻ
//dynamiteProgramming

int main(){
    long long n, number_i;
    vector<long long>sum_array;
    long long min_even=0, min_odd=LONG_LONG_MAX;
    long long max_even=LONG_LONG_MIN, max_odd=LONG_LONG_MIN;

    cin>>n;
    sum_array[0]=0;
    for(int i=1; i<n+1;i++){
        scanf("%lld",&number_i);//cộng thêm phần tử mới vào tổng thứ i
        sum_array[i]=sum_array[i-1]+number_i;
        //cập nhật các giá trị min max:
        if(sum_array[i]%2==0 && sum_array[i]<min_even) min_even=sum_array[i];
        if(sum_array[i]%2!=0 && sum_array[i]<min_odd) min_odd=sum_array[i];
        if(sum_array[i]%2==0 && sum_array[i]>max_even) max_even=sum_array[i];
        if(sum_array[i]%2!=0 && sum_array[i]>max_odd) max_odd=sum_array[i];
    }
    cout<<max(max_even-min_even, max_odd-min_odd);
    return 0;
}