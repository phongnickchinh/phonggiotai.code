    #include<bits/stdc++.h>
    using namespace std;

    //cấu trúc của mỗi giao dịch
    struct Transaction {
        string from_account;
        string to_account;
        int money;
        string time_point;
        string atm;
    };

    //hàm kiểm tra chu trình độ dài k
    bool hasCycle(map<string, set<string>> account, string& startAcc, unsigned int k) {
    queue<string> q;
    map<string, bool> visited;
    int rank_element[k + 1] = {};
    q.push(startAcc);
    visited[startAcc] = true;
    rank_element[0] = 1;

    for (unsigned int i = 0; i < k-1; i++) {
        cout << "rank_element[" << i << "] = " << rank_element[i] << endl;
            while (rank_element[i] > 0) {
                string u = q.front();
                cout<<"POP " << u << endl;
                q.pop();
                
                rank_element[i]--;
                for (const auto& v : account[u]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[u] = true;
                        cout<<"PUSH " << v << endl;
                        rank_element[i + 1]++;
                    }
                }
            }
    }
    visited[startAcc] = false;
    cout << "rank_element[" << k-1 << "] = " << rank_element[k-1] << endl;
    while(rank_element[k-1] > 0){
        string u = q.front();
        cout<<"POP " << u << endl;
        q.pop();
        rank_element[k-1]--;
        for (const auto& v : account[u]) {
            if(v == startAcc){
                return true;
            }
        }
    }
    return false;
}


    // hàm xử lý các câu truy vấn
    void processQueries(map<string, set<string>> account_map, const vector<Transaction>& transactions) {
        int number_transactions = transactions.size();
        int total_money_transaction = 0;
        set<string> account_set;
        map<string, int> money_transferred_from;

        for (const auto& transaction : transactions) {
            //Tổng tiền giao dịch
            total_money_transaction += transaction.money;
            account_set.insert(transaction.from_account);
            account_set.insert(transaction.to_account);

            //Tổng tiền được gửi từ mỗi tài khoản
            money_transferred_from[transaction.from_account] += transaction.money;
        }

        //Xử lý các câu truy vấn
        string query;
        while (getline(cin, query) && query != "#") {
            istringstream iss(query);
            string command;
            iss >> command;
            
            if (command == "?number_transactions") {
                //In ra số lượng giao dịch
                cout << number_transactions << endl;
            } else if (command == "?total_money_transaction") {
                //In ra tổng tiền giao dịch
                cout << total_money_transaction << endl;
            } else if (command == "?list_sorted_accounts") {
                for (const auto& account : account_set) {
                    //In ra danh sách tài khoản được sắp xếp theo thứ tự từ điển
                    cout << account << " ";
                }
                cout << endl;
            } else if (command == "?total_money_transaction_from") {
                string account;
                iss >> account;
                //In ra tổng tiền được gửi từ một tài khoản
                cout << money_transferred_from[account] << endl;
            } else if (command == "?inspect_cycle") {
                string account;
                unsigned int k;
                iss >> account >> k;
                //In ra 1 nếu có chu trình độ dài k, ngược lại in ra 0
                cout << (hasCycle(account_map, account, k) ? 1 : 0) << endl;
            }
        }
    }


    int main() {
        vector<Transaction> transactions; //danh sách các giao dịch
        map<string, set<string>> account_map; //danh sách các tài khoản gửi và nhận tiền, sử dụng cho tìm kiếm chu trình
        string line;
        freopen("test.txt", "r", stdin);
        while (getline(cin, line) && line != "#") {
            Transaction transaction;
            istringstream iss(line);
            iss >> transaction.from_account >> transaction.to_account >> transaction.money >> transaction.time_point >> transaction.atm;
            transactions.push_back(transaction);
            if(transaction.from_account != transaction.to_account){
                account_map[transaction.from_account].insert(transaction.to_account);
            }
        }

        //gọi hàm xử lý các câu truy vấn
        processQueries(account_map, transactions);

        return 0;
    }
