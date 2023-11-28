//Phạm Văn Phong - 20215448 _ 25/11/2023
#include <bits/stdc++.h>
using namespace std;

struct man {
    string ID;
    int birthday;
    string papaID;
    string mamaID;
    string isAlive;
    string regionID;
};
//Hàm chuyển đổi thời gian từ dạng YYYY-MM-DD sang dạng số ngày
int convertToInt(string time){
    return stoi(time.substr(0,4))*365+stoi(time.substr(5,2))*30+stoi(time.substr(8,2));
}

int main() {
    vector<man> dataBase;
    int totalPeople = 0;
    map<string, int> people_born_at;
    map<string,vector<string>> parent_of;
    map<string, vector<string>> children_of;

    //freopen("testCity.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string line, command;
    string temp, temp2;

    //Đọc dữ liệu từ file cho đến khi găp kí tự *:
    while(getline(cin, line)){
        if(line == "*"){
            break;
        }
        man person;
        stringstream ss(line);
        ss >> person.ID >> temp >> person.papaID >> person.mamaID >> person.isAlive >> person.regionID;
        person.birthday = convertToInt(temp);

        dataBase.push_back(person);
        totalPeople++;
        people_born_at[temp]++;
        if(person.papaID=="0000000" && person.mamaID=="0000000") children_of["0000000"].push_back(person.ID);
        if(person.papaID != "0000000"){
            parent_of[person.ID].push_back(person.papaID);
            children_of[person.papaID].push_back(person.ID);
        }
        if(person.mamaID != "0000000"){
            parent_of[person.ID].push_back(person.mamaID);
            children_of[person.mamaID].push_back(person.ID);
        }

    }
    //Sắp xếp dữ liệu theo thứ tự birthday:
    sort(dataBase.begin(), dataBase.end(), [](man a, man b) {
        return a.birthday <= b.birthday;
    });

    //Đọc các câu lệnh truy vấn từ file:
    cin >> command;
    while(command!="***"){
        if(command=="NUMBER_PEOPLE") printf("%d\n", totalPeople);
        if(command=="NUMBER_PEOPLE_BORN_AT"){
            cin >> temp;
            cout << people_born_at[temp] << endl;
        }
        if(command=="NUMBER_PEOPLE_BORN_BETWEEN"){
            cin >> temp >> temp2;
            int startTime = convertToInt(temp);
            int endTime = convertToInt(temp2);
            int revenue = 0;
            //tìm kiếm số thứ tự của đơn hàng đầu tiên có thời gian >= startTime
            int left = 0, right = dataBase.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (dataBase[mid].birthday >= startTime) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int firstOrderIndex = left;
            //tìm kiếm số thứ tự của đơn hàng cuối cùng có thời gian <= endTime
            left = 0, right = dataBase.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (dataBase[mid].birthday <= endTime) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int lastOrderIndex = right;
            //tổng doanh thu từ fistOrderIndex đến lastOrderIndex
            //bằng doanh thu từ đầu đến đơn hàng endTime trừ đi doanh thu từ đầu đến đơn hàng startTime
            revenue=lastOrderIndex-firstOrderIndex+1;
            cout << revenue << endl;
        }

        if(command=="MAX_UNRELATED_PEOPLE"){
            int result = 0;
            result+=children_of["0000000"].size();
            

            cout << result << endl;

        }
        if(command=="MOST_ALIVE_ANCESTOR"){
            //cout<<"NULL"<<endl;
            cin >> temp;
            int maxGen = 0;
            queue<pair<string, int>> q;
            q.push({temp, 0});
            while(!q.empty()){
                string curID = q.front().first;
                int curGen = q.front().second;
                q.pop();
                if(curGen>maxGen){
                    maxGen = curGen;
                }
                for(auto &id: parent_of[curID]){
                    q.push({id, curGen+1});
                }
            }
            cout << maxGen << endl;

        }
        cin>>command;
    }
}
