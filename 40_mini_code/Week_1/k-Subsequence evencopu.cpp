#include<bits/stdc++.h>
using namespace std;
//Tạo ra vector chứa tổng các tiền tố của vị trí thứ i
// tổng tiền tố là tổng của tất cả các hạng tử trước nó
vector<int> sum_preceding_numbers(const vector<int> &number_list) {
    vector<int> sum(number_list.size() + 1, 0);
    for (unsigned int i = 0; i < number_list.size(); i++) {
        sum[i + 1] = sum[i] + number_list[i];
    }
    return sum;
}
//tìm ra các tổng bao gồm k phần tử liên tiếp sao cho tổn đó chẵn
int count_even(const vector<int> number_list, int k) {
    int even_count = 0;
    vector<int> this_sum_preceding_numbers = sum_preceding_numbers(number_list);
    for (unsigned int i = 0; i <= number_list.size() - k; i++) {
        // tổng của k phần tử liên tiếp bằng đầu từ số thứ i
        //bằng tổng tiền tố của số thứ i+k trừ tổng tiền tố của số thứ i
        int subsquece_sum = this_sum_preceding_numbers[i + k] - this_sum_preceding_numbers[i];
        if (subsquece_sum % 2 == 0) even_count++;
    }
    return even_count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> number_list;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        number_list.push_back(number);
    }

    cout << count_even(number_list, k);
}
