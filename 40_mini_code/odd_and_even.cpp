#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> number_list;
    int n, count_odd=0, count_even=0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        int number;
        cin>>number;
        number_list.push_back(number);
    }

    for(int i=0; i<number_list.size(); i++){
        if(number_list[i]%2) count_even++;
        else count_odd++;
    }
    printf("%d %d", count_odd, count_even);
    return 0;
}