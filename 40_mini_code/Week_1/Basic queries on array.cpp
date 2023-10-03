#include<bits/stdc++.h>

using namespace std;
int find_max(vector<int> number_list){
    int max=number_list[0];
    for (const int  &number : number_list) max=max>number?max:number;
    return max; 
}

int find_min(vector<int> number_list) {
    if (number_list.empty()) {
        return 0; }

    int min = number_list[0];
    for (const int &number : number_list) {
        min = min < number ? min : number;
    }

    return min;
}

int find_max_segment(vector<int> number_list, int first, int last){
    int max=number_list[first-1];
    for (int i=first-1; i<=last-1; i++) max=max>number_list[i]?max:number_list[i];
    return max; 
}

int find_min_segment(vector<int> number_list, int first, int last){
    int min=number_list[first-1];
    for (int i=first-1; i<=last-1; i++) min=min<number_list[i]?min:number_list[i];
    return min; 
}

int sum(vector<int> number_list){
    int thissum=0;
    for (const int  &number : number_list) thissum+=number;
    return thissum; 
}

int main(){

    int n;
    scanf("%d",&n);

    //nhập vào 1 vector độ dài n:
    vector<int> number_list;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        number_list.push_back(number);
    }
    char dau_sao; cin>>dau_sao;

    string command;
    int f, l;
    //dùng các lệnh gọi hàm:
    while(cin>>command){
        
        if(command=="***") break; //end the loop
        else if(command=="find-max"){cout<<find_max(number_list)<<endl;}

        else if(command=="find-min") cout<<find_min(number_list)<<endl;

        else if(command=="sum") cout<<sum(number_list)<<endl;

        else if(command=="find-max-segment") {cin>>f>>l; cout<<find_max_segment(number_list,f,l)<<endl;}
        
        else if(command=="find-min-segment") {cin>>f>>l; cout<<find_min_segment(number_list,f,l)<<endl;}      
    }

    return 0;
}