#include<bits/stdc++.h>
using namespace std;
    struct TN{
        int value;
        TN* left;
        TN* right;
    };
//khai báo cái gốc null ban đầu:
TN* root=NULL;

//Tạo một nút từ dữ liệu nhập vào:
TN* makenewnode(int number){    
    TN* newnode=new TN;
    newnode->left=newnode->right=nullptr;
    newnode->value=number;
    return newnode;
}
//tạo 1 nốt mới có giá trị =number đưa vào bst,
//Số nhỏ hơn gốc sẽ được đưa về con trái và ngược lại, không có số lớn ngang bằng:
void insert_into_bst(TN* &root, int number){// đối số TN* &root đưa vào tham chiếu đến gốc cây
                                            // từ đó đem lại khả năng thay đổi giá trị của gốc
    TN* thisnode= makenewnode(number);
    if(root==NULL) {
        root=thisnode;
        return;
    }
    if(root!=NULL){
        if(root->value>number) insert_into_bst(root->left,number);
        else if(root->value<number) insert_into_bst(root->right, number);
    }
}
//in ra cây nhị phân theo thứ tự tiền:
void preorder(TN*root){
    if(root==NULL) return;
        cout<<root->value<<" "; 
        preorder(root->left);                                
        preorder(root->right);
    
}

int main(){
    string command;
    while(true){
        cin>>command;
        if(command=="#"){
            preorder(root);
            break;
        }
        //câu lệnh insert n:
        if(command=="insert"){
            int n; cin>>n;
            insert_into_bst(root, n);
        }
    }

    return 0;

}