#include<bits/stdc++.h>

using namespace std;


int main(){
    string acronym_word;
    string replace_word;
    string input_text;
    getline(cin,acronym_word); //từ viết tắt
    getline(cin,replace_word); //từ thay thế
    getline(cin,input_text); //văn bản

    int len=0;
    int n=0;
    while (input_text[n]!=NULL){
        
        //Kiểm tra độ dài từ trong văn b ản có giống từ viết tắt:
        if(input_text[n]==acronym_word[len]){
            //kiểm tra trùng kí tự:
            while(input_text[n]==acronym_word[len]&&input_text[n]!=NULL)
            {n++;
            len++;}

            //thay thế từ viết tắt bằng từ thay thế:
            if(len==acronym_word.length()&&(input_text[n]==' '||input_text[n]==NULL)){
                input_text.replace(n-len,len,replace_word);

            }
        }else while(input_text[n] != ' ') {
            n++;
            if(input_text[n] == '\0')
            break;
            }
        
        n++;
        len=0;
    }
    cout<<input_text;    
return 0;
}