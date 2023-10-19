#include <bits/stdc++.h>
using namespace std;
//trong bài này mình dùng biến tạm thời để duyệt, có thể dùng đệ quy cũng được đếy (nma ai rảnh):


//cấu trúc 1 nút, bao gồm dữ liệu và một con trỏ đến phần tử tiếp theo:
struct node {
    int data;
    node* next;
    node(int value) : data(value), next(NULL) {}
};


//kiểm tra trùng giá trị, nếu giá trị dã có trong danh sách, không làm gì cả:
bool isPresent(node* head, int value) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}


//thêm nút vào cuối danh sách, có thể làm thay đổi danh sách gốc:
void addLast(node* &head, int value) {
    if (isPresent(head, value)) return;
    node* newnode = new node(value);
    if (head == NULL) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

//thêm vào đầu danh sách. phải thay đổi danh sách gốc:
void addFirst(node* &head, int value) {
    if (isPresent(head, value)) return;
    node* newnode = new node(value);
    newnode->next = head;
    head = newnode;
}

//thêm vào sau nút cha, không thay đổi head nhận vào:
void addAfter(node* head, int key, int parent) {
    if (isPresent(head, key)) return;
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == parent) {
            node* newnode = new node(key);
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }
}
// thêm vào trước nút cha, có thể phải thay đổi nút head nhận vào:
void addBefore(node* &head, int key, int parent) {
    if (isPresent(head, key)) return;
    if (head == NULL) return;
    if (head->data == parent) {
        node* newnode = new node(key);
        newnode->next = head;
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == parent) {
            node* newnode = new node(key);
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }
}

//xoá nút:
void remove(node* &head, int value) {
    if (!isPresent(head, value)) return;//nếu nút không tồn tại thì thôi
    node* temp = head;
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }
    node* previous = NULL;
    while (temp != NULL && temp->data != value) {
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    previous->next = temp->next;
    delete temp;
}


//đảo ngược danh sách nhận vào:
void reverse(node* &head) {
    node *previous = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}


//inra:
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    //tạo nút đầu tiên của danh sách:
    node* head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        addLast(head, value);
    }

    string command;
    while (true) {
        cin >> command;
        if (command == "#") break;

        if (command == "addlast") {
            int value;
            cin >> value;
            addLast(head, value);
        } else if (command == "addfirst") {
            int value;
            cin >> value;
            addFirst(head, value);
        } else if (command == "addafter") {
            int key, value;
            cin >> key >> value;
            addAfter(head, key, value);
        } else if (command == "addbefore") {
            int key, value;
            cin >> key >> value;
            addBefore(head, key, value);
        } else if (command == "remove") {
            int value;
            cin >> value;
            remove(head, value);
        } else if (command == "reverse") {
            reverse(head);
        }
    }

    printList(head);

    return 0;
}
