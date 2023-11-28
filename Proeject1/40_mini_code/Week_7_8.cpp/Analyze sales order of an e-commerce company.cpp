// Creator: phonggiotai
//Phạm Văn Phong - 20215448 _ 20/11/2023
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//Khai báo kiểu dữ liệu của 1 đơn hàng
struct Order {
    string customerID;
    string productID;
    int price;
    string shopID;
    int timePoint;
};

//Hàm chuyển đổi thời gian từ dạng HH:MM:SS sang dạng số giây
int convertTimeToSecond(string time) {
    return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

int main() {

    //các cấu trúc lưu trữ dữ liệu:
    //orders: lưu trữ các đơn hàng
    //shopRevenue: lưu trữ doanh thu của các shop
    //customerShopRevenue: lưu trữ doanh thu của các khách hàng tại mỗi shop
    //totalRevenue: tổng doanh thu của cả hệ thống
    vector<Order> orders;
    unordered_map<string, int> shopRevenue;
    unordered_map<string, int> customerShopRevenue;
    int totalRevenue = 0;

    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string line, command, StimePoint;
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        Order order;
        iss >> order.customerID >> order.productID >> order.price >> order.shopID >> StimePoint;
        order.timePoint = convertTimeToSecond(StimePoint);
        orders.push_back(order);
        //tiền xử lí dữ liệu
        shopRevenue[order.shopID] += order.price;
        customerShopRevenue[order.customerID + order.shopID] += order.price;
        totalRevenue += order.price;
    }
    //Sắp xếp các đơn hàng theo thời gian
    sort(orders.begin(), orders.end(), [](Order a, Order b) {
        return a.timePoint <= b.timePoint;
    });

    //Quy hoạch động tính tổng doanh thu từ đầu đến thời gian của đơn hàng thứ i
    vector<int> RevenueinPeriod(orders.size());
    RevenueinPeriod[0]=orders[0].price;
    for(unsigned int i=1; i<RevenueinPeriod.size(); i++){
        RevenueinPeriod[i]=RevenueinPeriod[i-1]+orders[i].price;
    }

    // Xử lí truy vấn
    string p,q;
    cin>>command;
    while (command != "#") {
        if (command == "?total_number_orders") {
            printf("%d\n", orders.size());
        } else if (command == "?total_revenue") {
            printf("%d\n", totalRevenue);
        } else if (command=="?revenue_of_shop") {
            cin >> p;
            string shopID = p;
            printf("%d\n", shopRevenue[shopID]);
        } else if (command== "?total_consume_of_customer_shop") {
            cin >> p >>q;
            string customerID = p;
            string shopID = q;
            printf("%d\n", customerShopRevenue[customerID + shopID]);
        } else if (command== "?total_revenue_in_period") {
            cin>>p>>q;
            int startTime = convertTimeToSecond(p);
            int endTime = convertTimeToSecond(q);
            int revenue = 0;
            //tìm kiếm số thứ tự của đơn hàng đầu tiên có thời gian >= startTime
            int left = 0, right = orders.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (orders[mid].timePoint >= startTime) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int firstOrderIndex = left;
            //tìm kiếm số thứ tự của đơn hàng cuối cùng có thời gian <= endTime
            left = 0, right = orders.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (orders[mid].timePoint <= endTime) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int lastOrderIndex = right;
            //tổng doanh thu từ fistOrderIndex đến lastOrderIndex
            //bằng doanh thu từ đầu đến đơn hàng endTime trừ đi doanh thu từ đầu đến đơn hàng startTime
            if (firstOrderIndex <= lastOrderIndex) {
                revenue = RevenueinPeriod[lastOrderIndex] - RevenueinPeriod[firstOrderIndex] + orders[firstOrderIndex].price;
            }
            printf("%d\n", revenue);
        }  
        cin >> command;
    }

    return 0;
}