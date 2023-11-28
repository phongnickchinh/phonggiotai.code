#include<bits/stdc++.h>
using namespace std;
//bài toán: tính tổng của các biểu thức có dạng: a1*b1+a2*b2+...+an*bn
#define MOD 1000000007;
int main(){
    unsigned long long total=0;
    vector<string> term;
    string s;
    cin>>s;
    string temp="";
    unsigned int i=0;
    while(i<=s.length()){
        if(s[i]=='+'||i==s.length()){
            term.push_back(temp);
            temp="";
            i++;
        }else{
            temp+=s[i];
            i++;
        }
    }

    for(auto i: term){
        unsigned int j=0;
        unsigned long long tich=1;
        string temp="";
        while(j<=i.length()){
            //nếu gặp dấu nhân hoặc hết chuỗi thì thực hiện tính toán
            if(i[j]=='*'||j==i.length()-1){
                if(j==i.length()-1){
                    temp+=i[j];
                }
                tich*=stoi(temp);
                tich%=MOD;
                temp="";
                j++;
            }else{
                temp+=i[j];
                j++;
            }
        }
        //cộng vào tổng,
        total+=tich;
        total%=MOD;
        tich=1;
    }

    cout<<total;
    return 0;

}