#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int id;
    int maxValue;
    int leftValue;
    int rightValue;
    Node* rightChild;
    Node* leftChild;

    Node(int i, int l, int r, int v){
        id = i;
        leftValue = l;
        rightValue = r;
        maxValue = v;
        leftChild = nullptr;
        rightChild = nullptr;

    }
};

//cài đặt cây phân đoạn bằng cấu trúc cây nhị phân đầy đủ
class SecmentTree {
public:
    Node* root;
    vector<int> input;
public:
    SecmentTree(vector<int> arr){
        input = arr;
        Node* newNode = new Node(1, 1, arr.size(), INT_MIN);
        root = build(newNode);
    }
public:
    //hàm build ban đầu, cũng có thể dùng hàm này build lại nếu có thay đổi nhưng mà thôi ai lại làm thế.
    Node* build(Node* root){
        if(root->leftValue ==root->rightValue){
            root->maxValue = input[root->leftValue];
            return root;
        }
        int mid=(root->leftValue+root->rightValue)/2;
        Node *l_node = new Node(root->id*2+1, root->leftValue, mid, 99999);
        Node *r_node = new Node(root->id*2+2, mid+1, root->rightValue, 99999);
        root->leftChild = build(l_node);
        root->rightChild = build(r_node);
        root->maxValue = max(root->leftChild->maxValue, root->rightChild->maxValue);
        return root;

    }

    //các kiểu update hehehe
    Node* update(Node* root, int i, int v){
        input[i] = v;

        if(root->leftValue== root->rightValue && root->leftValue==i){
            root->maxValue = v;
            return root;
        }
        if(i<=root->leftChild->rightValue){
            update(root->leftChild, i, v);
            root->maxValue = max(root->leftChild->maxValue, root->rightChild->maxValue);
        }
        else{
            update(root->rightChild,i,v);
            root->maxValue = max(root->leftChild->maxValue, root->rightChild->maxValue);
        }
        return root;
    }

    int queryMax(Node* node, int u, int v){

        //case1: trường hợp uv và lr là 2 khoảng không liên quan gì đến nhau
        if (!node || node->rightValue < u || node->leftValue > v) return INT_MIN;

        //case 2: khi có 1 đoạn l,r đã được tính nằm hoàn toàn trong uv:
        //đừng thắc mắc tại sao nó đúng nữa, đã được chứng minh và thử nghiệm
        if(node->leftValue>= u && node->rightValue<=v) return node->maxValue;
        //case3: trường hợp thường
        int maxLeft = queryMax(node->leftChild, u, v);
        int maxRight = queryMax(node->rightChild, u, v);

        return max(maxLeft, maxRight);
    }

    int findMax(int u, int v){
        return queryMax(root, u,v);

    }
};

int main(){
    
    int n, q;
    scanf("%d", &n);
    vector<int> input(n+1, 0);
    for(int i=1;i<=n; i++){
        scanf("%d", &input[i]);
    }

    SecmentTree Phong(input);
    scanf("%d", &q);
    while(q--){
        string req;
        int u,v;
        cin >> req >> u >> v;
        if(req=="get-max") printf("%d\n", Phong.findMax(u,v));
        if(req=="update") {
            Phong.update(Phong.root, u, v);
            // printf("%d\n", u);
        }
    }
    return 0;
}