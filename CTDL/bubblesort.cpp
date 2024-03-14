#include <iostream>
#include <ctime>
#include <cstdlib>
#include<iomanip>

using namespace std;

int main(){
    clock_t start, end;
    
    int aray[1000]={};
   
    srand(time(NULL));
    for(int i=0; i<1000; i++){
      aray[i]= rand()%2000;
    }
   

cout<< "mang vua nhap la: ";
for (int  i = 0; i < 1000; i++)
{
    cout<<aray[i]<<"  ";   
} cout<<"\n";
//bắt đầu sắp xếp:
start= clock();
int swap=0;
for(int i=999; i>=0;i--){
    for (int j = 0; j<i; j++)
    {
      
      if(aray[j]>=aray[j+1]){
        swap=aray[j+1];
        aray[j+1]=aray[j];
        aray[j]=swap;
      }
      
        }
      for (int i = 0; i < 1000; i++)
        {
            cout<<aray[i]<<" ";
        }
      cout<<"\n";
      
    }
end= clock();
    long double alltime= (long double)(end-start)/CLOCKS_PER_SEC;
cout<<endl<<"mang sau sap xep la:"<<endl;
        for (int i = 0; i < 1000; i++)
        {
            cout<<aray[i]<<" ";
        }
    
    cout<<endl<<"thoi gian chay thuat toan:  "<< alltime;
    return 0;
    }