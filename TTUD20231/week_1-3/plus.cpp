    #include<bits/stdc++.h>
    using namespace std;


    int main(){
        string tamthoi="";
        string input;
        vector<int> number;
        int sum=0;
        getline(cin,input);
        for(unsigned int i=0; i<input.size();i++){
            if(input[i]==' '){
                cout<<"NOT_CORRECT";
                break;
            }
        }
                if(input[input.size()-1]=='+') cout<<"NOT_CORRECT";
                else{
                    for(unsigned int i=0; i<=input.size();i++){
                        if(input[i]>=48&&input[i]<=57)tamthoi.push_back(input[i]);
                        else{
                            int so=stoi(tamthoi);

                            number.push_back(so);
                            tamthoi="";
                        }   
                    }
                }

                for (auto &&i : number)
                {
                    sum+=i;
                }cout<<sum;
                

    }

    //1+12+10+123