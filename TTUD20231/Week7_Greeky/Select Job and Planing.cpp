#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    int deadline;
    int weight;
    Job(int d, int w): deadline(d), weight(w){};
};

//Lớp sử dụng để sắp xếp
class Planning{
    vector<Job> Lis;
    
    public:
    //Thêm 1 đối tượng kiểu Job danh sách cần lựa chọn sắp xếp:
    void addJob(int d, int w){
        Job newjob(d, w);
        Lis.push_back(newjob);
    }
    //Sắp xếp theo thứ tự không giảm khối lượng của các Job
    void sortLis(){
        sort(Lis.begin(), Lis.end(), [](const Job &a, const Job &b) {
            return a.weight >= b.weight;});
    }
    //sử dụng thuật toán tham lam chọn dần các đoạn kết quả lớn nhất mà phù hợp:
    int find_solution(int n){
        int total=0;
        vector<int> result(n,0);
        for(unsigned int i=0; i<Lis.size(); i++){
            for ( int j=Lis[i].deadline-1; j>=0;j--){
                if( result[j]==0){ total+=Lis[i].weight; result[j]=1; break;}
            }
        }
        return total;
    }
};


int main(){
    int n;
    Planning P;
    cin>>n;
    int deadline, weight;
    for(int i=0; i<n; i++){
        scanf("%d%d", &deadline, &weight);
        P.addJob(deadline,weight);
    }
    P.sortLis();
    cout<<P.find_solution(n);
    return 0;
}