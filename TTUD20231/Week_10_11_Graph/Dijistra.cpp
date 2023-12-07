#include <iostream>

// Định nghĩa cấu trúc Node để lưu trữ danh sách kề
struct Node {
    int connectedVertex, weight;
    Node *next;
    Node(int v, int w, Node *n) {
        connectedVertex = v;
        weight = w;
        next = n;
    }
};

// Mảng lưu trữ danh sách kề
Node *adjacencyList[100001];

// Mảng lưu trữ trọng số ngắn nhất
int shortestWeights[100001] = {};

// Mảng lưu trữ các đỉnh
int vertices[1000001] = {};

int main() {
    int numVertices, numEdges, start, end, weight, pos = -1, index = 1, minWeight = 2147483647;

    // Nhập số lượng đỉnh và số lượng cạnh
    scanf("%d %d", &numVertices, &numEdges);

    // Đọc dữ liệu cạnh và trọng số từ bàn phím
    while (numEdges--) {
        scanf("%d %d %d", &start, &end, &weight);
        adjacencyList[start] = new Node(end, weight, adjacencyList[start]);
    }

    // Nhập đỉnh đầu và đỉnh cuối
    scanf("%d %d", &start, &end);
    vertices[0] = start;

    // Duyệt đồ thị bằng thuật toán Dijkstra
    while (++pos < index) {
        Node *temp = adjacencyList[vertices[pos]];
        int currentWeight = vertices[++pos];
        while (temp) {
            // Kiểm tra và cập nhật trọng số ngắn nhất
            if (!shortestWeights[temp->connectedVertex] || shortestWeights[temp->connectedVertex] > currentWeight + temp->weight) {
                if (minWeight > currentWeight + temp->weight) {
                    if (temp->connectedVertex == end)
                        minWeight = currentWeight + temp->weight;
                    vertices[++index] = temp->connectedVertex;
                    vertices[++index] = currentWeight + temp->weight;
                    shortestWeights[temp->connectedVertex] = currentWeight + temp->weight;
                }
            }
            temp = temp->next;
        }
    }

    // In ra trọng số ngắn nhất từ đỉnh đầu đến đỉnh cuối
    printf("%d", shortestWeights[end]);
    return 0;
}
