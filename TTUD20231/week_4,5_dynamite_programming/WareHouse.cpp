#include <bits/stdc++.h>
using namespace std;

struct Node {
    int amount, timeLeft;
    Node *next;

    Node(int amount, int timeLeft, Node *n) : amount(amount), timeLeft(timeLeft), next(n) {}
};

Node *s[1001];

int main() {
    int n, T, D, a[1001], t[1001], mx = 0;
    scanf("%d %d %d", &n, &T, &D);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        s[i] = new Node(a[i], T - t[i], nullptr);
    }

    for (int i = 2; i <= n; ++i) {
        int opt[T] = {};

        for (int j = 1; j <= D && j < i; ++j) {
            Node *temp = s[i - j];

            while (temp) {
                int timeLeft = temp->timeLeft - t[i];
                int accumulatedAmount = temp->amount + a[i];

                if (timeLeft >= 0 && opt[timeLeft] <= accumulatedAmount) {
                    opt[timeLeft] = accumulatedAmount;
                    s[i] = new Node(accumulatedAmount, timeLeft, s[i]);
                    mx = max(s[i]->amount, mx);
                }

                temp = temp->next;
            }
        }
    }

    printf("%d\n", mx);

    return 0;
}
