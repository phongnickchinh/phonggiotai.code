#include<stdio.h>
#define MAX_N 10001
int input_array[MAX_N], list_quantity[MAX_N], n, max_sequence=-1;



int main(){
    scanf("%d", &n);
    list_quantity[0]=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &input_array[i]);
        list_quantity[i]=1;
        for(int j=1; j<i; j++){
            if(input_array[i]>input_array[j]){
                if(list_quantity[i]<(list_quantity[j]+1)) list_quantity[i]=list_quantity[j]+1;
            }
        }
        max_sequence = max_sequence>list_quantity[i]?max_sequence:list_quantity[i];
    }

    printf("%d", max_sequence);
    return 0;
}