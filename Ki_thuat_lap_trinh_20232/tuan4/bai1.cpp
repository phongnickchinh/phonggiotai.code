/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    struct Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node *temp = head, *reve = NULL;
    while(temp->next != 0){
        reve = prepend(reve, temp->data);
        temp = temp->next;
    }
    return prepend(reve, temp->data);
}
  
// print the list content on a line
void print(Node* head) {
    Node *temp = head;
    while(temp->next != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}