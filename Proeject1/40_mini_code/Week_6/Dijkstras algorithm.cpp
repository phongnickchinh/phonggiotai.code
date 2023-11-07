//Phạm Văn Phong 20215448_7/11/2023
#include <bits/stdc++.h>
using namespace std;

//1 lớp dành cho thuật toán dijktra, ý tưởng của thuật toán 
//này là cập nhật tăng dần khoảng cách từ nguồn đến các đỉnh còn lại
//trong quá trình duyệt nếu có đường đi nào ngắn hơn cái đã có thì sẽ được cập nhật vào bảng kết quả
//have fun!!!!
class Dijkstra
{
public:
    int numberofNodes;
    vector<vector<int>> arcList;
    Dijkstra(int n) : numberofNodes(n), arcList(n + 1, vector<int>(n + 1, INT_MAX)) {}

public:
    //nhập vào cung và trọng số của nó:
    void addDistance(int u, int v, int w)
    {
        arcList[u][v] = w;
    }

    //phương thức tìm đường đi ngắnn nhất từ u đến v bằng dijktra's:
    void solution_dijktra(int source, int destination)
    {
        vector<int> visited(numberofNodes + 1, 0);
        vector<int> result(numberofNodes + 1, INT_MAX);
        result[source] = 0;
        int curNode = source;
        visited[source] = 1;
        int n = numberofNodes;

        while (n > 0)
        {
            for (int i = 1; i <= numberofNodes; i++)
            {   
                //nếu có đường đi từ nút current đến nút i
                // và đường đi từ nút nguồn đến nút i thông qua nút current
                // là tốt hơn so với trước đó thì cập nhật lại đường đi nhỏ nhất đến nút i
                if (arcList[curNode][i] != INT_MAX && result[i] > result[curNode] + arcList[curNode][i])
                {
                    result[i] = result[curNode] + arcList[curNode][i];
                }
            }
            visited[curNode] = 1;
            int mindistance = INT_MAX;

            //sau khi duyệt, cập nhật đỉnh được duyệt tiếp theo, và độ dài tới đỉnh đó
            for (int i = 1; i <= numberofNodes; i++)
            {
                if (visited[i] == 0 && mindistance > result[i])
                {
                    curNode = i;
                    mindistance = result[i];
                }
            }

            //nếu đã tới đích, kết thúc:
            if (curNode == destination)
                break;
            else
            {
                n--;
            }
        }

        //sau khi kết thúc vòng lặp, in ra độ dài đường đi
        if (result[destination] == INT_MAX) cout << INT_MAX << endl;
        else{
            cout << result[destination] << endl;
        }
    }
};

int main()
{
    int nodes, arcs;
    cin >> nodes >> arcs; //nhập vào số đỉnh, số cung
    Dijkstra d(nodes);
    int u, v, w;
    for (int i = 0; i < arcs; i++)
    {
        cin >> u >> v >> w; //nhập vào cung (u,v) có trọng số w
        d.addDistance(u, v, w);
    }
    cin >> u >> v; //nhập vào đỉnh nguồn và đỉnh đích
    d.solution_dijktra(u, v);
    return 0;
}
