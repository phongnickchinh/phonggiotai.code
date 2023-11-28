//Phạm Văn Phong - 20215448 _ 26/11/2023
#include <bits/stdc++.h>
using namespace std;
//lưu lại các thông tin của 1 user
struct User {
    int errSub;//số lần nộp bài sai
    int OkSub;//số lần nộp bài đúng
    int totalScore;//tổng số điểm
};

//chuyển đổi thời gian từ dạng hh:mm:ss sang số giây
int convertTime(string time) {
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');
    int s = (time[6] - '0') * 10 + (time[7] - '0');
    return h * 3600 + m * 60 + s;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //lưu lại các thông tin của các user, sử dụng unordered_map để tìm kiếm nhanh
    unordered_map<string, User> userList;
    int totalSubmissions = 0;//tổng số lần nộp bài
    int totalErrSubmissions = 0;//tổng số lần nộp bài sai
    vector<int> subTime(86405, 0);//lưu lại số lượng submissions tại mỗi thời điểm
    //lưu lại điểm cao nhất của mỗi user tại mỗi problem, unordered_map giúp tìm kiếm nhanh
    unordered_map<string, unordered_map<string, int>> maxScoreEachUser;

    string ID, PID, time, status;
    int score;

    cin >> ID;
    //đọc dữ liệu từ file input cho đến khi gặp kí tự #
    while (ID != "#") {
        cin >> PID >> time >> status >> score;

        //cập nhật điểm cao nhất của mỗi user tại mỗi problem
        //câp nhật lại tổng số điểm của mỗi user
        int temp = max(maxScoreEachUser[ID][PID], score);
        userList[ID].totalScore += temp - maxScoreEachUser[ID][PID];
        maxScoreEachUser[ID][PID] = temp;

        totalSubmissions++;
        subTime[convertTime(time)]++;

        if (status[0] == 'E') {
            userList[ID].errSub++;
            totalErrSubmissions++;
        } else {
            userList[ID].OkSub++;
        }

        cin >> ID;
    }

    // tính tổng số lượng submissions tại mỗi thời điểm, sử dụng quy hoạch động
    for (unsigned int i = 1; i < subTime.size(); i++) {
        subTime[i] += subTime[i - 1];
    }

    string command, a, b;
    cin >> command;

    //đọc các câu lệnh điều khiển từ file input cho đến khi gặp kí tự #
    while (command != "#") {
        if (command == "?total_number_submissions") {
            cout << totalSubmissions << endl;
        } else if (command == "?number_error_submision_of_user") {
            cin >> a;
            cout << (userList.find(a) != userList.end() ? userList[a].errSub : 0) << endl;
        } else if (command == "?number_error_submision") {
            cout << totalErrSubmissions << endl;
        } else if (command == "?total_point_of_user") {
            cin >> a;
            cout << (userList.find(a) != userList.end() ? userList[a].totalScore : 0) << endl;
        } else if (command == "?number_submission_period") {
            cin >> a >> b;
            cout << subTime[convertTime(b)] - (convertTime(a) > 0 ? subTime[convertTime(a) - 1] : 0) << endl;
        }

        cin >> command;
    }

    return 0;
}
