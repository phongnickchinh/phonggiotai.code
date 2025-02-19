#include<stdio.h>
#include<math.h>
//mảng chứa giải pháp tại cột i:
int result[1000];
int number_sol=0;
int n;
int banco[1000][1000];
char yes='n';

//check if the new queen not eat any other queen
int check(int i, int k){
    //kiểm tra hàng
    if(result[k]!=-1000) return 0; 
    for (int p=1; p<=n; p++){
        //kiểm tra cột
        if(result[p]==i) return 0;
        //kiểm tra đường chéo
        if(result[p]!=-1000 && p!=k){
            if(abs(k-p)==abs(i-result[p])) return 0;
        }
    }
    return 1;

}

void solution(){
    number_sol++;
    //print the chess board:
    if (yes=='r'){
        for (int i=1; i<=n; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    if(yes=='y'){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(j==result[i]) printf("1 ");
                else printf("0 ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return;


}

void Try(int k){
    for(int hehe=1; hehe<=n; hehe++){
        if(check(hehe,k)==1){
            result[k]=hehe;
            if(k==n) solution();
            else Try(k+1);
        }
    }
    result[k]=-1000;
    result[k-1]=-1000;
    return;
}

int main(){
    printf("nhap vao do lon ban co n:");
    scanf("%d", &n);
    printf("y: print all board, r: Print simple, n: not print?(y/r/n)");
    scanf(" %c", &yes);
    for(int i=1; i<=n; i++){
        result[i]=-1000;
    }
    Try(1);
    printf("number of solution: %d", number_sol);
    return 0;

}