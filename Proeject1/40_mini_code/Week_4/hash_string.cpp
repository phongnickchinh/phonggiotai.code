#include <stdio.h>
#include <string.h>

// Hàm tính mã băm cho một chuỗi
int calculate_hash_code(char* s, int k, int m) {
    int hash_code = 0;
    for (int i = 0; i < k; i++) {
        hash_code = (hash_code * 256 + s[i]) % m;//công thức truy hồi h(s+1)=(256h(s)+s[i])%m
    }
    return hash_code;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char buffer[201]; // Dùng để đọc chuỗi đầu vào, đảm bảo đủ kích thước

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        int k = strlen(buffer);
        int hash_code = calculate_hash_code(buffer, k, m);
        printf("%d\n", hash_code);
    }

    return 0;
}