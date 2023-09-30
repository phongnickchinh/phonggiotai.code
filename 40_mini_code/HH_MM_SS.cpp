    #include <iostream>
    #include <string>
    using namespace std;
//xin chào tôi sẽ comment vào đây
bool isInteger(const string& str) {
    // Kiểm tra từng ký tự trong chuỗi
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // Nếu có ký tự không phải chữ số, trả về false
        }
    }
    return true; // Nếu toàn bộ chuỗi đều là chữ số, trả về true
}
    int main() {
        string input;
        cin >> input;

        //kiểm tra độ dài
        if (input.length()==8&& input[2]==':'&&input[5]==':'){
            string hour=input.substr(0,2);
            string minute=input.substr(3,2);
            string second=input.substr(6,2);

            //kiểm tra liệu có phải kí tự số
            if (isInteger(hour)&&isInteger(minute)&&isInteger(second)){
                int hour_int=stoi(hour);
                int minute_int=stoi(minute);
                int second_int=stoi(second);
            
                //kiểm tra số có hợp lệ
                if(hour_int>=0&&hour_int<=23&& minute_int>=0&&minute_int<=59&& second_int>=0&&second_int<=59){
                    int Total_second= hour_int*3600+minute_int*60+second_int;
                    cout<<Total_second;
                }else cout<<"INCORRECT";
                
            }else cout<<"INCORRECT";
            
        }else cout<<"INCORRECT";
        

        return 0;
    }
