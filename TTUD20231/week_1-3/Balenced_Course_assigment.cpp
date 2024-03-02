#include<bits/stdc++.h>
#define M 50
using namespace std;
/// course_teacher là mản lưu trữ thông tin môn học i có những giáo viên j nào dạy
//time_overlap là mảng lưu trữ các  môn trùng lịch
//result lưu lại kết quả chia công việc hợp lệ
//appear lưu lại số môn học mà mỗi gv dạy
//bắt đầu thoi!!
int Couser_teacher[M][M],time_overlap[M][M], result[M];
int appear[M]={0};
int  teacher, course;
//last_solution để lưu lại kết quả cuối
int last_solution=INT_MAX;

//hàm check xem xếp môn học k cho gv v có hợp lệ hay không
bool check(int k, int v){
    if(Couser_teacher[v][k]==0) return false; //gv cần biết dạy môn học
    //gv đã dạy một môn nào đó trước k, mà môn đó lại trùng thời gian với k thì chịu:
    for(int i=1; i<k; i++) {
        if(time_overlap[i][k]==1&&result[i]==v) return false;
    }
    return true;
}

//hàm chọn ra số môn học tối đa mà gv được chia,
//so sánh với kỉ lục trước đó chọn ra kỉ lục mới:
void max_appear(){
    int maxl=0;
    for(int i=1; i<=teacher; i++) maxl=max(maxl,appear[i]);
    last_solution=min(maxl,last_solution);
}

//tìm kiếm các giải pháp
void Find_solution(int k){
    //khi đệ quy chạm tới môn học cuối cùng, chuyển sang hàm xử lí kết quả:
    if(k>course){ 
        max_appear();
        return;
    }
    for(int v=1; v<=teacher;v++){ 
        //kiểm tra nếu hợp lệ sẽ điền gv v vào môn học k
        if(check(k,v)){ 
            result[k]=v;
            //tăng biến đếm số môn học được chia của v thêm 1
            appear[v]++; 
            //sử dụng nhánh cận, cắt tỉa các nhánh cho ra kết quả không khả thi
            //tức là số môn học nhận được của gv v bất kì lớn hơn kỉ lục
            if(appear[v]<last_solution) Find_solution(k+1); 
            appear[v]--; //sau khi backtrack, giảm số môn nhận được của v đi 1, để thử với v+1
        }

    }

}
int main(){
    //nhập vào matran gồm teacher hàng và course cột
    cin>>teacher>>course;
    for(int i=1;i<=teacher;i++){
        int monhoc;
        cin>>monhoc;
        for( int j=1; j<=monhoc; j++){
            int vitri;
            cin>>vitri;
            Couser_teacher[i][vitri]=1;
        }
    }
    //nhập vào ma trận các môn bị trùng
    int overlaps;
    cin>>overlaps;
    for(int i=1;i<=overlaps;i++){
        int a,b;
        cin>>a>>b;
        time_overlap[a][b]=1;
        time_overlap[b][a]=1;
    }
    //bắt đầu xét môn học đầu tiên  
    Find_solution(1);
    cout<<last_solution;
}