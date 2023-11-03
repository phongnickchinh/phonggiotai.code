#include<bits/stdc++.h>
using namespace std;

class secment
{
public:
int start, end;
public:
secment(int s, int e):start(s), end(e){};

int distance(){
    return end-start;
}
};

class greeky{
    vector<secment> Lis;

public:
    void addSecment(int s, int e){
        secment Newsecment(s,e);
        Lis.push_back(Newsecment);
    }

    //Sắp xếp cái list theo thứ tự không giảm của điểm cuối mỗi đoạn
    void sortSecment(){
         sort(Lis.begin(), Lis.end(), [](const secment& a, const secment& b) {
            return a.end <= b.end;});        
    }
    //Sử dụng thamlam tìm kết quả:
    int count_greeky_solution(){
        int last=Lis[0].end;
        int count=1;
        for(unsigned int i=1; i<=Lis.size();i++){
            if(last<=Lis[i].start){
                count++;
                last=Lis[i].end;
            }
        }
        return count;
    }




};

int main (){
    int n;
    cin>>n;
    int s, e;
    greeky P;
    for(int i=0; i<n; i++){
        scanf("%d%d", &s,&e);
        P.addSecment(s,e);
    }
    P.sortSecment();
    cout<<P.count_greeky_solution();
    return 0;
}


