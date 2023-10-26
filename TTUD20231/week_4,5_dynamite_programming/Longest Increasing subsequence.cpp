#include<bits/stdc++.h>
using namespace std;
//thuật toán lày chạy với thời gian O(n^2)
//Người ta bảo có thể dùng AVL tree để giảm xuống còn nlogn but i dont know how to do
 int main (){
    int n, solution=INT_MIN;
    scanf("%d", &n);
    int number[n];
    int list[n]; // lưu lại dãy con lớn nhất đối với số thứ i
    for(int i=0; i<n; i++){
        scanf("%d", &number[i]);
    }
    list[0]=1;

    //quét một lượt các dãy trước i, tìm các dãy phù hợp cho number_i
    //dãy có nhiều phần tử nhất sẽ được lưu lại
    for(int i=1; i<n; i++){
        list[i]=1;
        for(int j=0; j<i; j++){
            if(list[j]>=list[i] && number[i]>number[j]) list[i]=list[j]+1;
        }
        solution=max(list[i], solution); //cập nhật kỉ lục

    }
    cout<<solution;
    return 0;
 }