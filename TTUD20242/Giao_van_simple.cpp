//Bài toán đơn giản này chỉ yêu cầu đếm số phương án chia, không yêu cầu tính quãng đường
//yêu cầu sử dụng tất cả các xe
//điều kiện tính là 1 phương án: số xe được dùng = k, số khách được phục vụ = n.
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_K 100
#define MOD 100000

int n, K;
string result="";
int car[MAX_K+2];
int serviced[MAX_N+2];

string operator+(const string& a, const string& b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while(i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0 ? a[i--] - '0' : 0);
        int digitB = (j >= 0 ? b[j--] - '0' : 0);
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        res += (sum % 10 + '0');
    }

    reverse(res.begin(), res.end());
    return res;
}

string operator*(const string& a, const string& b) {
    // Nhân hai số lớn dạng chuỗi
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p1] += sum / 10;
            res[p2] = sum % 10;
        }
    }

    string result;
    for (int num : res)
        if (!(result.empty() && num == 0))
            result += (char)(num + '0');
    return result.empty() ? "0" : result;
}


string operator/(const string& a, const string& b) {
    if (b == "0") throw invalid_argument("Division by zero");
    if (a == "0") return "0";

    string result, remainder;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        remainder += a[i];
        // Loại bỏ số 0 ở đầu
        while (remainder.size() > 1 && remainder[0] == '0')
            remainder.erase(remainder.begin());

        int quotient_digit = 0;
        while (remainder.size() > b.size() || (remainder.size() == b.size() && remainder >= b)) {
            int carry = 0;
            string temp;
            // Thực hiện remainder = remainder - b
            int i1 = remainder.size() - 1;
            int i2 = b.size() - 1;
            while (i1 >= 0 || i2 >= 0 || carry) {
                int x = (i1 >= 0 ? remainder[i1] - '0' : 0);
                int y = (i2 >= 0 ? b[i2] - '0' : 0) + carry;

                if (x < y) {
                    x += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }

                temp += ((x - y) + '0');
                i1--; i2--;
            }

            reverse(temp.begin(), temp.end());
            // Loại bỏ số 0 ở đầu
            int first_non_zero = 0;
            while (first_non_zero < temp.size() && temp[first_non_zero] == '0')
                first_non_zero++;
            remainder = (first_non_zero == temp.size()) ? "0" : temp.substr(first_non_zero);

            ++quotient_digit;
        }

        result += (quotient_digit + '0');
    }

    // Loại bỏ số 0 ở đầu kết quả
    int start = 0;
    while (start < result.size() - 1 && result[start] == '0')
        start++;

    return result.substr(start);
}


string factorial(int p) {
    string res = "1";
    for (int i = 2; i <= p; i++) {
        res = res*to_string(i);
    }
    return res;
}

bool no_empty_car(){
    for(int i=1; i<=K; i++){
        if(!car[i]) return false;
    }
    return true;
}

//phương án xét cho từng khách hàng
void Try(int k){
    int remaining = n - k + 1;
    int unused_car = 0;
    for(int i = 1; i <= K; i++){
        if(car[i] == 0) unused_car++;
    }

    if(remaining < unused_car) return; // CẮT TỈA MẠNH
    if(k==(n+1)){
        if(no_empty_car()) {
            string way = "1";
            for (int i = 1; i <= K; i++) {
                way = (way * factorial(car[i]));
            }
            result = (result + way);
        }
        return;
    }
    for(int j=1; j<=K; j++){
        car[j]++;
        serviced[k]=j;
        if(car[j]<=(n-K+1)) Try(k+1);
        car[j]--;
    }
}


int main(){
    cin>>n>>K;
    Try(1);
    result = result/factorial(K);
    string last5 = result.substr(max(0, (int)result.size() - 5)); 
    cout<<endl<<last5;
    return 0;
}
