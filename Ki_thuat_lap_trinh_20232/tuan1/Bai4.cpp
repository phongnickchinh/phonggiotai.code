//Phạm Văn Phong, 20215448, 738919
#include<iostream>

using namespace std;

int counteven(int* arr, int size){
	int count = 0;  // biến đếm số chẵn
    for(int i = 0; i < size; i++){   // xét từng phần tử trong mảng
    	if(arr[i]%2 == 0)   // nếu phần tử chia hết cho 2
    		count++;    // thì biến đếm cộng thêm 1
    }
	return count;   // trả về số lượng số chẵn trong mảngmảng
}

int main(){
	int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
	cout << counteven(arr, 8) << endl;
    int arr1[] = {1, 5, 4, 0, 10, 7};
    cout << counteven(arr1, 6);
}