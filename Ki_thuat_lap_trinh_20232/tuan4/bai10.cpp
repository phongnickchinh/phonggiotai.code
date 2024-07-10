#include<iostream>
#include<time.h>
#include<math.h>
#include<map>

using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/

struct node{
    string a;
    int index;
    node *next;
    node(string x, int i, node *ds){
        a = x;
        index = i;
        next = ds;
    }
};

node *ds[18000];

int main(){
    // file test10.txt luu test case 5 
    freopen("test10_5.txt", "r", stdin);
    string s, t, x = "";
    int n, q, temp = 0, sl[1000] = {}, vb;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s; s += ","; // nhap van ban thu i
        map<string, int> m;
        sl[i] = 1;
        for(int j = 0; j < (int) s.size(); ++j)
            if(s[j] == 44){ // voi moi 1 tu trong van ban
                map<string, int>::iterator ite = m.find(x); // tim xem da co tu do chua
                if(ite == m.end())
                    m.insert({x, 1}); // chua thi them vao tu dien mini
                else{
                    ite->second += 1;
                    sl[i] = max(ite->second, sl[i]); // tim gia tri max f(d,t)
                }
                int m = min((int) x.size(), 3);
                for(int k = 0; k < m; ++k)   temp += (x[k] - 97) * pow(26, 2 - k); // luu vao danh sach lien ket ls[temp] dua vao 3 chu cai dau tien cua tu do 
                ds[temp] = new node(x, i, ds[temp]);
                x = "";
                temp = 0;
            }
            else
                x += s[j];
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        double score[n] = {}, mx = 0.0;
        cin >> t; t += ","; // nhap truy van thu i
        for(int j = 0; j < (int) t.size(); ++j){
            if(t[j] == 44){
                int m = min((int) x.size(), 3), sol = 0, sco[n] = {};
                for(int k = 0; k < m; ++k)   temp += (x[k] - 97) * pow(26, 2 - k); // tim den lk[temp] dua vao 3 chu cai dau tien cua tu do
                if(ds[temp] != NULL){
                    node *p = ds[temp];
                    while(1){ // tim co tu do khong
                        if(p->a == x)
                            sco[p->index] += 1; // co thi tang bien dem len 1
                        if(p->next == NULL) break;
                        p = p->next;
                    }
                    for(int k = 0; k < n; ++k) 
                        if(sco[k] != 0) 
                            sol += 1; // so luong van ban chua tu do
                    double idf = log2((double) n / (double) sol); // tinh idf
                    for(int k = 0; k < n; ++k)
                        if(sco[k] != 0)
                            score[k] += (0.5 + 0.5 * ((double) sco[k] / sl[k])) * idf; // cong diem cho moi van ban
                }
                x = "";
                temp = 0;
            }
            else
                x += t[j];
        }

        for(int k = 0; k < n; ++k) 
            if(score[k] > mx){ // tim van ban co diem cao nhat
                mx = score[k];
                vb = k;
            }
        cout << vb + 1 << endl;
    }
}