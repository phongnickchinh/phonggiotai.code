#include<iostream>
#include<cstring>
#include<cmath>
//Manage student with ID is primerykey
typedef struct sinhvien
{
    char ID[8];
    sinhvien* next;

} sv;



//Make newnode and add to your list
void addnode(sv* &head, char ID[8], int location) {
    sv* newsv = new sv;
    strcpy(newsv->ID, ID);
    newsv->next = NULL;

    if (head == NULL) {
        // Danh sách liên kết rỗng, nút mới sẽ là nút đầu tiên
        head = newsv;
        return; // Đã thêm nút mới, thoát khỏi hàm
    }

    if (location == 0) {
        // Thêm nút mới vào vị trí đầu tiên của danh sách liên kết
        newsv->next = head;
        head = newsv;
    } else {
        // Thêm nút mới vào vị trí khác trong danh sách liên kết
        sv* currentnode = head;
        int i = 1;
        while (currentnode->next != NULL && i < location) {
            currentnode = currentnode->next;
            i++;
        }

        // Kiểm tra nếu vị trí location không hợp lệ, nút mới sẽ được thêm vào cuối danh sách
        newsv->next = currentnode->next;
        currentnode->next = newsv;
    }
}
int deletenode(sv *head, char ID[8]){

    if(head==NULL) return 1;

}



