#include<bits/stdc++.h>
using namespace std;

struct TN{
    int id;
    TN* left;
    TN* mid;
    TN* right;
};
    TN* root=NULL;
//Tạo 1 nút mới:
TN* makeNewNode(int id)
{
    TN* newNode = new TN;
    newNode->left = newNode->right = newNode->mid= NULL;
    newNode->id = id;
    return newNode;
}

// chèn nút mới vào làm con của nút có id_parent, nếu là chèn lần đầu thì là gốc:
void insert_into_root(TN*root,int id, int id_parent){// đối số TN* root đưa tham 1 tham số là vị trí của gốc cây, 
//chỉ có thể thay đổi các nút con thông qua con trỏ left right, không cho phép thay đổi giá trị của gốc
    TN*thisnode= makeNewNode(id); //tạo nút mới bằng cái id nhập vào
    if(root==NULL) return;
    if(root!=NULL&&root->id==id_parent){
        if(root->left==nullptr) root->left=thisnode;
        else{
            if(root->mid==nullptr) root->mid=thisnode;
            else{
                if(root->right==nullptr) root->right=thisnode;
            }
        }return;
    }
    //nếu nút không có id_parent hợp thì đệ quy tới nút bên dưới:
    insert_into_root(root->left,id, id_parent);
    insert_into_root(root->mid,id, id_parent);
    insert_into_root(root->right,id, id_parent);

    
}

//cây theo thứ tự trước: trái->gốc->giữa->phải
void print_tree_inorder(const TN* root)
{
    if (NULL == root) return;
    print_tree_inorder(root->left);
    printf("%d ", root->id);
    print_tree_inorder(root->mid);                                  
    print_tree_inorder(root->right);
}

//In cây bằng thứ tự preoder: gốc->trái->giữa->phải
void print_tree_preorder(const TN* root)
{
    if (NULL == root) return;
    printf("%d ", root->id);
    print_tree_preorder(root->left);
    print_tree_preorder(root->mid);                                  
    print_tree_preorder(root->right);
}

//in cây bằng postoder trái->giữa ->phải->gốc
void print_tree_postorder(const TN* root)
{
    if (NULL == root) return;

    print_tree_postorder(root->left);
    print_tree_postorder(root->mid);                                  
    print_tree_postorder(root->right);
    printf("%d ", root->id);
}
int main(){

    int n;
    int m;
    string command;
    while(true){
        cin>>command; //đọc lệnh nhập từ bàn phím
        
        if(command=="*") break;

        if(command=="MakeRoot"){
            cin>>n;
            root=makeNewNode(n);
        }
        if(command=="Insert"){
            cin>>n>>m; 
            insert_into_root(root,n,m); //này tương đương với lệnh nhập từ bàn phím:
                                        // Insert id id_parent
        }
        if(command=="InOrder") {print_tree_inorder(root); cout<<endl;}
        if(command=="PreOrder") {print_tree_preorder(root); cout<<endl;}
        if(command=="PostOrder") {print_tree_postorder(root); cout<<endl;}
    }
    return 0;
}