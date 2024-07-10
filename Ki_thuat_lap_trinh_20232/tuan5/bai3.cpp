#include <iostream>
using namespace std;
#include <string.h>
#include <stack>
 
int par(string str){
    int a = str.length();
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    if (S.empty()){
        return 1;
    }
    else return 0;
}
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    int n;
    string str;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }
    
    return 0;
}