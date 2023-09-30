    #include <iostream>
    #include <string>
    using namespace std;

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
        if (input.length()==10&& input[4]=='-'&&input[7]=='-'){
            string year=input.substr(0,4);
            string month=input.substr(5,2);
            string day=input.substr(8,2);

            //kiểm tra liệu có phải kí tự số
            if (isInteger(year)&&isInteger(month)&&isInteger(day)){
                int year_int=stoi(year);
                int month_int=stoi(month);
                int day_int=stoi(day);
            
                //kiểm tra số có hợp lệ
                if(year_int>=1&&year_int<=9999&& month_int>=1&&month_int<=12&& day_int>=1&&day_int<=31){
                    cout<<year_int<<" "<<month_int<<" "<<day_int;
                }else cout<<"INCORRECT";
                
            }else cout<<"INCORRECT";
            
        }else cout<<"INCORRECT";
        

        return 0;
    }
