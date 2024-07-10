#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    int i = 0;
    while(i < (int)a.size()){
        if(!(a.at(i) & 1))
            a.erase(a.begin() + i);
        else
            ++i;
    }
}

void sort_decrease(vector<int> &a) {
    sort(a.begin(), a.begin() + a.size(), greater<int>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    for(int i=0; i < (int)b.size(); ++i){
        c.insert(c.begin(), b.at(i));
    }
    for(int i=0; i < (int)a.size(); ++i){
        c.insert(c.begin(), a.at(i));
    }
    sort_decrease(c);
    return c;
}
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}