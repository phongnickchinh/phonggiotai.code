// Phạm Văn Phong, 20215448, 738919

#include<iostream>

using namespace std;

void reversearray(int arr[], int size){
    int r = size - 1, tmp;
    for(int i = 0; i < size/2; i++){    // chạy i từ 0 đến một nửa mảng
    	tmp = arr[i];                   // gán giá trị phần tử i trỏ tới vào tmp
    	arr[i] = arr[r - i];            // gán giá trị phần tử i bằng phần tử đối xứng qua mảng
    	arr[r-i] = tmp;                 // gán giá trị tạm thời tmp vào phần tử đối xứng
	}
}

// hàm ptr_reversearray tương tự ch
void ptr_reversearray(int *arr, int size){
int *a = arr, *b = arr + size - 1, tmp; // con trỏ a trỏ từ phần tử đầu tiên, con trỏ b trỏ tới phần tử đối xứng
    while(b > a){                       // khi con trỏ a trỏ tới phần tử phía trước con trỏ b thì tiếp tục
        tmp = *a;
        *a = *b;
        *b = tmp;                       // đổi giá trị 2 phần tử 2 con trỏ trỏ tớitới
        a++;
        b--;                            // trỏ tới giá trị tiếp theo
    }
}

int main(){
    int arr[] = {9, 3, 5, 6, 2, 5};
    reversearray(arr, 6);
    for(int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    int arr2[] = {4, -1, 5, 9};
    ptr_reversearray(arr2, 4);
    for(int i = 0; i < 4; i++)
        cout << arr2[i] << " ";
}