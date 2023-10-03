#include<bits/stdc++.h>
using namespace std;

vector<int> sum_preceding_numbers(const vector<int> &number_list) {
    vector<int> sum(number_list.size() + 1, 0);
    for (unsigned int i = 0; i < number_list.size(); i++) {
        sum[i + 1] = sum[i] + number_list[i];
    }
    return sum;
}

int count_even(const vector<int> number_list, int k) {
    int even_count = 0;
    vector<int> this_sum_preceding_numbers = sum_preceding_numbers(number_list);
    for (unsigned int i = 0; i <= number_list.size() - k; i++) {
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
