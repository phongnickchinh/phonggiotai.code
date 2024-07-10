#include <iostream>
#include <set>

using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/
template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    std::set<T> c;
    for(auto i = a.begin(); i != a.end(); ++i){
        c.insert(*i);
    }
    for(auto i = b.begin(); i != b.end(); ++i){
        c.insert(*i);
    }
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    std::set<T> c;
    for(auto i = a.begin(); i != a.end(); ++i){    
        auto j = b.find(*i);
        if(j != b.end() || *i == *b.end())
            c.insert(*i);
    }
    return c;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);

    return 0;
}