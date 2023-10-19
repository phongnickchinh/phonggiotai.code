    #include<bits/stdc++.h>
    #define M 50
    using namespace std;
    /// course_periods là mản lưu trữ thông tin môn học i có những giáo viên j nào dạy
    //time_overlap là mảng lưu trữ các  môn trùng lịch
    //result lưu lại kết quả chia công việc hợp lệ
    //credit_period lưu lại số môn học mà mỗi gv dạy
    //bắt đầu thoi!!
    int time_overlap[M][M], result[M];
    int credit_period[M]={0};
    int credit_period_course[M];
    int  periods, course;
    //last_solution để lưu lại kết quả cuối 
    int last_solution=INT_MAX;

    //hàm check xem xếp môn học k cho gv v có hợp lệ hay không
    bool check(int k, int v){
        for(int i=1; i<k; i++) { 
            if(time_overlap[i][k]==1&&result[i]>=v) return false;
        }
        return true;
    }


    void max_credit_period(){
        int maxl=0;
        for(int i=1; i<=periods; i++) maxl=max(maxl,credit_period[i]);
        last_solution=min(maxl,last_solution);

    }

    //tìm kiếm các giải pháp
    void Find_solution(int k){
        //khi đệ quy chạm tới môn học cuối cùng, chuyển sang hàm xử lí kết quả:
        if(k>course){ 
            max_credit_period();
            return;
        }
        for(int v=1; v<=periods;v++){ 
            //kiểm tra nếu hợp lệ sẽ điền gv v vào môn học k
            if(check(k,v)){ 
                result[k]=v;
                //tăng biến đếm số môn học được chia của v thêm 1
                credit_period[v]+=credit_period_course[k]; 
                //sử dụng nhánh cận, cắt tỉa các nhánh cho ra kết quả không khả thi
                //tức là số môn học nhận được của gv v bất kì lớn hơn kỉ lục
                if(credit_period[v]<last_solution) Find_solution(k+1); 
                credit_period[v]-=credit_period_course[k]; //sau khi backtrack, giảm số môn nhận được của v đi 1, để thử với v+1
            }

        }

    }
    int main(){
    //nhập vào số môn, số kì:
    cin>>course>>periods;
        //nhập vào ma trận các môn hhàng j phải học trước cột j:
        for(int i=1;i<=course;i++) cin>>credit_period_course[i];

        for(int i=1;i<=course;i++){
            for(int j=1; j<=course;j++) cin>>time_overlap[i][j];
        }
        //bắt đầu xét môn học đầu tiên  
        Find_solution(1);
        cout<<last_solution;
    }