#include<bits/stdc++.h>
using namespace std;

//dùng map để lưu trữ mỗi gia đình: bao gồm 1 cha và vector lưu các con:
map<string, vector<string>> children_of; 

//đếm số hậu duệ của 1 người, 
//bằng các đếm số con của người đó và con của con
//và con của con của con... :)
int countDescendants(string SameRankSiblings) {
    if (children_of.find(SameRankSiblings) == children_of.end()) {
        return 0;
    }
    int count = children_of[SameRankSiblings].size();
    for (string child : children_of[SameRankSiblings]) {
        count += countDescendants(child);
    }
    return count;
}


//Đếm số đời sau của 1 người
//bằng cách đưa tên ông này vào danh sách chờ duyệt
//mỗi vòng lặp đưa vào danh sách duyệt các hậu duệ có cùng rank( 1:các con, 2:các cháu...) 
//tăng số đời lên 1
//lặp lại đến khi các hậu duệ xa nhất chưa có con, hoặc không thể có con:((


//Đếm số đời sau của 1 người
int countGeneration(string name) {
   queue<string> SameRankSiblings; //hàng đợi để duyệt dần từ rank cao đến thấp
    SameRankSiblings.push(name);
    int generations = 0;

    //vòng lặp dừng khi hết hậu duệ:
    while (!SameRankSiblings.empty()) {
        int size = SameRankSiblings.size();

        //vòng lặp này dừng khi duyệt tìm hết con của các gia đình cùng rank
        while (size--) {
            string checkname = SameRankSiblings.front();
            SameRankSiblings.pop();
            if (children_of.find(checkname) != children_of.end()) {
                for (string child : children_of[checkname]) {
                    SameRankSiblings.push(child);
                }
            }
        }
        //mỗi khi duyệt xong 1 rank, tăng bộ đếm:
        generations++;
    }
    //lần duyệt với thế hệ cuối chưa có con thì không được tính:
    return generations - 1; 
}

int main() {
    string child, parent_name;
    while (true) {
        cin >> child;
        if (child == "***") {
            break;
        } 
        cin >> parent_name;
        children_of[parent_name].push_back(child);
    }

    string command, name_to_search;
    while (true) {
        cin >> command;
        if (command == "***") break;
        if (command == "descendants") {
            cin >> name_to_search;
            cout << countDescendants(name_to_search) << endl;
        }
        if (command == "generation") {
            cin >> name_to_search;
            cout << countGeneration(name_to_search) << endl;
        }
    }

    return 0;
}