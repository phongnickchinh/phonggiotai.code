#include<iostream>
#include<cstring>

using namespace std;

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
Do bài này tự viết hàm nên em có thay đổi cấu trúc bigNum sao cho phù hợp với cách làm của mình và giúp tối ưu hiệu năng.
*/

// Cấu trúc bigNum cho những số lớn.
struct bigNum{
    int numLen; // Độ dài bigNum.
    int sign = 1; // Dấu của bigNum.
    int num[101] = {};  // Giá trị bigNum.
};

// Nhập giá trị bigNum gồm dấu (sign) và giá trị của bigNum.
void input(bigNum &bn){
    string s;
    cin >> s;
    int length = s.length() - 1, i, k = length;
    
    bn.numLen = length;
    bn.sign = s[0] - 48;
    for(i = 0; i < length; i++)
        bn.num[i] = s[k--] - 48;
}

// Setbni: Đặt giá trị i có kiểu int vào một bigNum có dấu là sign.
bigNum setbni(int sign, int i){
    bigNum setbni;
    for(int j = 0; j < 8; j++){
        setbni.num[j] = i % 10;
        i /= 10;
    }
    setbni.numLen = 1;
    setbni.sign = sign;
    return setbni;
}

// Hàm so sánh 2 bigNum, nếu bn1 lớn hơn bn2 thì trả về true.
bool compare(bigNum bn1, bigNum bn2){
    if(bn1.numLen > bn2.numLen)
        return true;
    else{
        if(bn1.num[bn2.numLen] > bn2.num[bn2.numLen])
            return true;
        else
            return false;
    }
}

// Phép cộng: Mặc định là 2 số dương cộng với nhau, số đầu lớn hơn số thứ hai.
bigNum add(bigNum bn1, bigNum bn2){
    bigNum sum;
    int temp = 0, add, len = bn1.numLen, i;
    
    // Cộng từng chữ số từ nhỏ đến lớn của 2 bigNum vào biến add và có nhớ vào biến temp.
    for(i = 0; i < len; i++){
        add = bn1.num[i] + bn2.num[i] + temp;
        temp = add / 10;
        sum.num[i] = add - temp * 10;
    }
    sum.num[i] = temp;
    if(temp == 0)
        sum.numLen = len;
    else
        sum.numLen = len + 1;

    return sum;
}

// Phép trừ: Mặc định là 2 số dương, số đầu tiên lớn hơn trừ đi số thứ hai.
bigNum sub(bigNum bn1, bigNum bn2){
    bigNum diff;
    int temp = 0, sub, len, i;

    // Trừ từng chữ số từ nhỏ tới lớn của 2 bigNum vào biến sub và có nhớ vào temp.
    len = bn1.numLen;
    for(i = 0; i < len; i++){
        sub = bn1.num[i] - bn2.num[i] + temp;
        if(sub < 0){
            sub = 10 + sub;
            temp = -1;
        }
        else
            temp = 0;
        diff.num[i] = sub % 10;
    }
    while(diff.num[len--] == 0);
    diff.numLen = len + 2;

    return diff;
}

// Toán tử '+', tùy giá trị của bigNum1 và bigNum2 mà so sánh bằng hàm compare và gọi hàm add hoặc sub cho phù hợp. 
bigNum operator + (bigNum bn1, bigNum bn2){
    bigNum result;

    if(bn1.sign == 0){
        if(bn2.sign == 0){
            result = add(bn1, bn2);
            result.sign = 0;
        }
        else{
            if(compare(bn1, bn2)){
                result = sub(bn1, bn2);
                result.sign = 0;
            }
            else{
                result = sub(bn2, bn1);
            }
        }
    }
    else{
        if(bn2.sign == 0){
            if(compare(bn1, bn2)){
                result = sub(bn1, bn2);
            }
            else{
                result = sub(bn2, bn1);
                result.sign = 0;
            }
        }
        else
            result = add(bn1, bn2);
    }

    return result;
}

// Toán tử '-', tùy giá trị của bigNum1 và bigNum2 mà so sánh bằng hàm compare và gọi hàm add hoặc sub cho phù hợp. 
bigNum operator - (bigNum bn1, bigNum bn2){
    bigNum result;

    if(bn1.sign == 0){
        if(bn2.sign == 0){
            if(compare(bn1, bn2)){
                result = sub(bn1, bn2);
                result.sign = 0;
            }
            else{
                result = sub(bn2, bn1);
            }
        }
        else{
            result = add(bn1, bn2);
            result.sign = 0;
        }
    }
    else{
        if(bn2.sign == 0)
            result = add(bn1, bn2);
        else{
            if(compare(bn1, bn2)){
                result = sub(bn1, bn2);
            }
            else{
                result = sub(bn2, bn1);
                result.sign = 0;
            }
        }
    }

    return result;
}

// Toán tử '*', tùy dấu của 2 bigNum mà trả về dấu âm hoặc dương.
bigNum operator * (bigNum bn1, bigNum bn2){    
    bigNum result;

    int num[101] = {}, num1, len1 = bn1.numLen, len2 = bn2.numLen, i, j;
    
    // Nhân mặc định là 2 số dương nhân với nhau.
    // Nhân từng chữ số của 2 bigNum sau đó cộng vào phần tử trong mảng num[101] tương ứng.
    for(i = 0; i < len1; i++){
        num1 = bn1.num[i];
        for(j = 0; j < len2; j++)
            num[i + j] += num1 * bn2.num[j]; 
    }

    // Do cộng xong lên đến hàng chục, trăm, ngàn nên phải đưa các phần tử về đơn vị.
    for(i = 0; i < 100; i++){
        num[i + 1] += num[i] / 10;
        num[i] %= 10;
    }

    // Lưu vào bigNum result và lấy độ dài.
    for(i = 0; i < 101; i++){
        result.num[i] = num[i];
        if(num[i] > 0)
            result.numLen = i;
    }
    result.numLen += 1;

    // Xét dấu kết quả theo bn1, bn2.
    int sig = bn1.sign + bn2.sign;
    if(sig == 1)
        result.sign = 0;
    else
        result.sign = 1;

    return result;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){

    // Tạo và nhập giá trị 2 bigNum.
    bigNum a, b;
    input(a);
    input(b);
    
    // Tạo các số 3, 4 dưới dạng bigNum.
    bigNum bn3 = setbni(1, 3);
    bigNum bn4 = setbni(1, 4);
    
    // Tính hàm cần tính bằng toán tử và in ra.
    bigNum func = a * b - bn3 * a + bn4 * b ;
    cout << func.sign; 
    for(int i = func.numLen - 1; i > -1; i--)
        cout << func.num[i];
}