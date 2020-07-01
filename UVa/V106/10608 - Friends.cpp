#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000 + 5;

int n, m;
int boss[MAXN];

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (boss[a] > boss[b]) {
            swap(a, b);
        }
        boss[a] += boss[b];
        boss[b] = a;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            boss[i] = -1;
        }

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            uni(a, b);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (boss[i] < 0) {
                ans = max(ans, abs(boss[i]));
            }
        }
        cout << ans << '\n';
    }
}