//Phạm Văn Phong, 20215448, 738919

#include<stdio.h>

double* maximum(double* a, int size){
    double *max; // con trỏ tới giá trị lớn nhất
    max = a; // ban đầu trỏ tới phần tử đầu tiên
    if (a == NULL)
        return NULL; // nếu mảng rỗng, trả về NULL
    for(int i = 0; i < size; i++){
        if(a[i] > *max){    // nếu phần tử nào lớn hơn giá trị con trỏ trỏ tới
            max = a + i;    // con trỏ trỏ tới phần tử đó
        }
    }
    return max;
}

int main(){
    double arr[] = {1., 10., 2., -7., 25., 3.};
    double* max = maximum(arr, 6);
    printf("%.0f", *max);
}