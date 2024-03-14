#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void sort(int *aray, int n){
    int swap=0;
for(int i=n-1; i>=0;i--){
    for (int j = 0; j<i; j++)
    {
      
      if(aray[j]>=aray[j+1]){
        swap=aray[j+1];
        aray[j+1]=aray[j];
        aray[j]=swap;
      }
      
        }
    }
}

void random(int *array, int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
      array[i]= rand()%(10*n);
    }
}

void read(int *array, int n){
    for (int i = 0; i < n; i++)
        {
            cout<<array[i]<<" ";
        }
}

void sortsortedlist(int*array, int n, int *brray, int m, int *crray){
    int i=0,j=0,k=0;
    while(i<n||j<m){
        if(array[i]<=brray[j]) crray[k++]=array[i++];
        else crray[k++]=brray[j++];

    }
    if(i<n) while(i<n) crray[k++]=array[i++];
    if(j<m) while (j<m) crray[k++]=brray[j++];
}

int main(){
    int n,m,count;
    cin>>n;cin>>m;

    int ar[n], br[m];
    int totallist[n+m];

    random(ar,n);
    random(br,m);
 
    cout<<endl<<"mang a duoc tao:"<<endl;    
    read(ar,n);
    cout<<endl<<"mang b duoc tao:"<<endl;
    read(br,m);

    sort(ar,n);
    sort(br,m);

    cout<<endl<<"mang a sau sap xep la:"<<endl;
    read(ar,n);
    cout<<endl<<"mang b sau sap xep la:"<<endl;
    read(br,m);

    sortsortedlist(ar,n,br,m,totallist);

    cout<<endl<<"mang tong hop:"<<endl<<endl;
    read(totallist,n+m);
   
return 0;

}