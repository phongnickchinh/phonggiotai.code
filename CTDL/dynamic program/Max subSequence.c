#include<stdio.h>


int main(){
    int n, maxValue, minValue, num;
    scanf("%d", &n);
    int totalArray[n];
    int input[n];
    scanf("%d", &num);
    totalArray[0]=num;


    for(int i= 1; i<n; i++){
        scanf("%d", &input[i]);
        totalArray[i]= totalArray[i-1]+input[i];
        maxValue = totalArray[i]>maxValue?totalArray[i]:maxValue;
        minValue = totalArray[i]<minValue?totalArray[i]:minValue;
    }

    printf("%d", maxValue - minValue);
    return 0;

}