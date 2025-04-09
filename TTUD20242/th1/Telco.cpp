#include<bits/stdc++.h>
using namespace std;

struct Person
{
    int call_from;
    int call_time; //second
    /* data */
};

int incorrect_num=0;
int total_call=0;


int count_time(string start_time, string end_time){

    int h= stoi(start_time.substr(0,2));
    int m = stoi(start_time.substr(3,2));
    int s= stoi(start_time.substr(6,2));
    int s_start= h*3600+m*60+s;

    int h_e= stoi(end_time.substr(0,2));
    int m_e = stoi(end_time.substr(3,2));
    int s_e= stoi(end_time.substr(6,2));
    int s_end= h_e*3600+m_e*60+s_e;

    return s_end - s_start;
}

int check_phone(string &str){
    if(str.length()<10) return 0;
    for(char c: str){
        if(!isdigit(c)) return 0;
    }
    return 1;
}

int main(){
    map<string,Person> listNum;
    string f_number;
    string t_number;
    string st_time, end_time, not_imp;
    string order="call";
    while (true)
    {
        cin>>order;
        if(order=="#") break;
        cin>>f_number >> t_number >> not_imp >> st_time >>end_time;
        total_call++;
        listNum[f_number].call_from++;
        listNum[f_number].call_time +=count_time(st_time,end_time);
        if(!check_phone(f_number) || check_phone(t_number)) incorrect_num=1;
    }

    string order_num;
    order="?";
    while(true){
        cin>>order;
        if(order=="#") break;

        if(order=="?check_phone_number") cout<<incorrect_num<<endl;
        if(order=="?number_calls_from"){
            cin>>order_num;
            cout<<listNum[order_num].call_from<<endl;
        }

        if(order=="?number_total_calls") cout<<total_call<<endl;
        if(order=="?count_time_calls_from"){
            cin>>order_num;
            cout<<listNum[order_num].call_time<<endl;
        }
    }

    return 0;
    
}


