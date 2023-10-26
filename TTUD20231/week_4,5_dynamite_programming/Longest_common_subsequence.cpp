//Phạm Văn Phong 20215448 _ 26/10/2023 hôm qua em đến trường mẹ dắt tay từng bước ớ ơ
#include <bits/stdc++.h>
using namespace std;
//tham khảo lời giải tại https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

//tìm số phần tử của dãy con giống nhau dài nhất
//bằng cách sử dụng mảng ghi nhớ
//số phần tử của dãy dài nhất tính đến phần tử thứ i

//tìm số phần tử của dãy con giống nhau dài nhất
int longestCommonSubsequence(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    // initializing 2 vectors of size m
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    //thiết lập các giá trị cơ sở:
    for (int idx2 = 0; idx2 < m + 1; idx2++)
        cur[idx2] = 0;

    //duyệt lần lượt từ trên xuống:
    for (int idx1 = 1; idx1 < n + 1; idx1++) {
        for (int idx2 = 1; idx2 < m + 1; idx2++) {
            //nếu có phần tử giống nhau:
            if (nums1[idx1 - 1] == nums2[idx2 - 1])
                cur[idx2] = 1 + prev[idx2 - 1];

            // nếu không giống:
            else
                cur[idx2] = 0 + max(cur[idx2 - 1], prev[idx2]);
        }
        prev = cur;
    }

    return cur[m]; //giá trị góc phải dưới cùng là kết quả bài toán,
                   //có thể dùng các kí tự đánh dấu để ghi nhớ quá trình lựa chọn
                   //từ đó in ra được dãy con này nếu đề bài yêu cầu
}

int main()
{
    vector<int> nums1, nums2;
    int n, m, temp;
    cin>>n>>m;
    for(int i=0;i<n; i++) {
        scanf("%d", &temp);
        nums1.push_back(temp);
    }
    for(int i=0;i<m; i++) {
        scanf("%d", &temp);
        nums2.push_back(temp);
    }
    cout <<longestCommonSubsequence(nums1, nums2);
    return 0;
}
