#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, m, pre[MAXN], q[MAXN];
string s;

int is_convex(int x1, int x2, int x3, int x4) {
    return (pre[x2] - pre[x1 - 1]) * (x4 - x3 + 1) - (pre[x4] - pre[x3 - 1]) * (x2 - x1 + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + s[i - 1] - '0';
        }

        int ansl = 1, ansr = m, front = 0, rear = 0;
        for (int i = m; i <= n; i++) {
            while (rear - front > 1 && is_convex(q[rear - 2], i - m, q[rear - 1], i - m) >= 0) {
                rear--;
            }
            q[rear++] = i - m + 1;
            while (rear - front > 1 && is_convex(q[front], i, q[front + 1], i) <= 0) {
                front++;
            }
            int ret = is_convex(q[front], i, ansl, ansr);
            if (ret > 0 || (ret == 0 && i - q[front] < ansr - ansl)) {
                ansl = q[front];
                ansr = i;
            }
        }

        cout << ansl << " " << ansr << "\n";
    }
}