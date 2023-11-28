//Phạm Văn Phong - 20215448 _ 19/11/2023
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;
// các biến toàn cục:
// transactionAmount: mảng lưu số tiền giao dịch của mỗi tài khoản
// path: mảng lưu đường đi từ đỉnh đích đến đỉnh đích
// numTransactions: số lượng giao dịch
// totalMoney: tổng số tiền giao dịch
// m: độ dài chu trình cần tìm
// targetAccount: đỉnh đích
// isCycleFound: biến kiểm tra xem có chu trình độ dài m hay không
// accountIndex: số lượng tài khoản
// visited: mảng đánh dấu các đỉnh đã được duyệt
// uniqueAccounts: tập hợp các tài khoản
// accountMapping: map lưu tên tài khoản và chỉ số của tài khoản đó trong mảng transactionAmount
int numTransactions = 0, totalMoney = 0, m, targetAccount,  accountIndex = 0;
int transactionAmount[100001] = {}, path[100001];
int isCycleFound = 0;
bool visited[100001];
set<string> uniqueAccounts;
map<string, int> accountMapping;
vector<int> adjacencyList[100001];

//hàm kiểm tra chu trình độ dài k
void findCycle(int k){
    //nếu đã tìm thấy chu trình nhưng chưa đến độ dài k thì không cần kiểm tra nữa    
    if(isCycleFound){
        return;
    }
    //nếu độ dài chu trình bằng k thì kiểm tra xem đỉnh cuối có phải là đỉnh đích không
    if(k == m){
        for(int neighbor : adjacencyList[path[k-1]])
            if(neighbor == targetAccount)
                isCycleFound = 1;
        return;
    }
    //nếu chưa đủ k đỉnh thì tiếp tục duyệt các đỉnh kề với đỉnh trước đó
    for(int neighbor : adjacencyList[path[k - 1]]){
        if(!visited[neighbor]){
            path[k] = neighbor;
            visited[neighbor] = true;
            findCycle(k+1);
            visited[neighbor] = false;
        }
    }
}

int main(){
    //freopen("test.txt", "r", stdin);
    //lệnh này giúp tăng tốc độ đọc và ghi trên cin và cout
    ios::sync_with_stdio(false);
    cin.tie(0);
    string sender, receiver, atmCode;
    cin >> sender; //biến vừa có chức năng nhận lệnh, vừa có chức năng nhận tên tài khoản
    while(sender[0] != '#'){
        //tiền xử lí dữ liệu
        cin >> receiver >> m >> atmCode >> atmCode;
        numTransactions++;
        totalMoney += m;
        if(uniqueAccounts.find(sender) == uniqueAccounts.end()){
            accountMapping[sender] = accountIndex++;
        }      
        if(uniqueAccounts.find(receiver) == uniqueAccounts.end()){
            accountMapping[receiver] = accountIndex++;
        }
        transactionAmount[accountMapping[sender]] += m;
        uniqueAccounts.insert(sender);
        uniqueAccounts.insert(receiver);
        adjacencyList[accountMapping[sender]].push_back(accountMapping[receiver]);
        cin >> sender;
    }
    cin >> sender; 
    while(sender[0] != '#'){
        if(sender[1] == 't'){
            //lệnh ?total_money_transaction_from
            if(sender[28] == 'm'){
                cin >> sender;
                if(uniqueAccounts.find(sender) != uniqueAccounts.end()){
                    cout << transactionAmount[accountMapping[sender]] << endl;
                }
                
                else
                    cout << 0 << endl;
            }
            //lệnh ?total_money_transaction
            else{
                cout << totalMoney << endl;
            }
        }
        //lệnh ?inspect_cycle
        else if(sender[1] == 'i'){
            cin >> sender >> m;
            isCycleFound = 0;
            targetAccount = accountMapping[sender];
            path[0] = targetAccount;
            visited[targetAccount] = true;
            findCycle(1);
            visited[targetAccount] = false;
            if(isCycleFound){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        //leehnj ?list_sorted_accounts:
        else if(sender[1] == 'l'){
            for(string account : uniqueAccounts)
                cout << account << " ";
            cout << endl;
        }
        //lệnh ?number_transactions:
        else if(sender[1] == 'n'){
            cout << numTransactions << endl;
        }
        cin >> sender;
    }
    return 0;
}
