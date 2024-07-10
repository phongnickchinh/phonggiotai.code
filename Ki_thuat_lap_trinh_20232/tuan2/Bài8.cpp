#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    int val1, val2, i, j, k, x, y, z;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    vector<int> temp;
    
    // Sắp xếp chọn
    for(i=0; i<(int)a.size()-1; i++){
        x = 0;
        z = i;
        
        // Tính tổng của vecto thứ i lưu vào x
        for(j = 0; j < (int) a[i].size(); j++)
            x += a[i][j];
        
        // Lần lượt tính tổng các vecto còn lại. 
        for(j = i + 1; j < (int) a.size(); j++){
            y = 0;
            for(k = 0; k < (int) a[j].size(); k++)
                y += a[j][k];
        
            // Nếu lớn hơn x hiện tại thì lưu vị trí vào z, lưu tổng vào x 
            if(y > x){
                x = y;
                z = j;
            }
        }
        // Đổi vị trí 2 vecto cho vecto tổng lớn hơn ở trước.
        temp = a[z];
        a[z] = a[i];
        a[i] = temp;
    }

    // In ra vecto sau khi sắp xếp.
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}