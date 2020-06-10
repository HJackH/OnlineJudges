#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000 + 5;

int n, m, boss[MAXN];

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (boss[x] > boss[y]) {
            swap(x, y);
        }
        boss[x] += boss[y];
        boss[y] = x;
    }
}

int main() {
    int kase = 0;
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i <= n; i++) {
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
                ans++;
            }
        }
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
}