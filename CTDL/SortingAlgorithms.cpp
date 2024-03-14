#include <iostream>
#include<string>



void insertsort(int *array, int n){
    int temparray[n];
    for(int i=0, i<n, i++){
        int vtmax=n-1;

        for(int j=n-1, j>i,j--){
            if(array[vtmax]>=array[j]) vtmax=j;
             
        }
    }
}
