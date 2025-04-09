#include<stdio.h>
#define MAX_N 31

// Cấu trúc lưu trạng thái gồm: a, b, số bước step và chỉ số cha parent_idx
typedef struct
{
    int a, b;
    int step, parent_idx;
} state;

int a, b, x, y;
state queue[MAX_N*MAX_N];
int front=0, last=0;
int visited[MAX_N][MAX_N];

// Lấy phần tử đầu hàng đợi
state getFront(){
    return queue[front];
}
// Lấy và xoá phần tử đầu hàng đợi
state pop(){
    state temp = queue[front];
    front++;
    return temp;
}
// Thêm phần tử vào cuối hàng đợi
void push(state Ele){
    queue[last] = Ele;
    last++;
}
// Kiểm tra hàng đợi rỗng
int empty(){
    return front >= last;
}

// Kiểm tra trạng thái có hợp lệ không
int isValid(int a, int b){
    if(a > 30 || b > 30 || a < 0 || b < 0) return 0;
    if(visited[a][b]) return 0;
    return 1;
}

// In lại đường đi từ trạng thái đầu tiên tới trạng thái hiện tại
void print(int idx){
    if(idx == -1) return;
    print(queue[idx].parent_idx);
    printf(" (%d %d)", queue[idx].a, queue[idx].b);
}

int main(){
    scanf("%d%d%d%d", &a, &b, &x, &y);

    // Trường hợp đặc biệt: trạng thái ban đầu là (0, 0)
    if(a == 0 && b == 0){
        printf("0 (%d %d)", a, b);
        return 0;
    }
    if(a==x && b==y){
        printf("0 (%d %d)", a, b);
        return 0;
    }

    // Khởi tạo trạng thái ban đầu
    state first_state = {a, b, 0, -1};
    push(first_state);
    visited[a][b] = 1;

    // BFS tìm đường đi ngắn nhất
    while (!empty()){
        state temp = pop();

        // Nếu đạt trạng thái cần tìm thì in kết quả và thoát
        if(temp.a == x && temp.b == y){
            printf("%d", temp.step);
            print(front-1);
            return 0;
        }

        // Thao tác I: Trừ a cho b
        if(isValid(temp.a - temp.b, temp.b)){
            visited[temp.a - temp.b][temp.b] = 1;
            push((state){temp.a - temp.b, temp.b, temp.step + 1, front - 1});
        }

        // Thao tác II: Cộng a với b
        if(isValid(temp.a + temp.b, temp.b)){
            visited[temp.a + temp.b][temp.b] = 1;
            push((state){temp.a + temp.b, temp.b, temp.step + 1, front - 1});
        }

        // Thao tác III: Đổi chỗ a và b
        if(isValid(temp.b, temp.a)){
            visited[temp.b][temp.a] = 1;
            push((state){temp.b, temp.a, temp.step + 1, front - 1});
        }
    }

    // Không tìm được đường đi
    printf("-1");
    return 0;
}
