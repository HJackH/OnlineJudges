#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 50;

int n, a[MAXN], ls[MAXN], rs[MAXN];

bool canGive(int q) {
    int x = ls[1] = a[1], y = q - x;
    rs[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            rs[i] = min(a[i], y - rs[i - 1]);
            ls[i] = a[i] - rs[i];
        } else {
            ls[i] = min(a[i], x - ls[i - 1]);
            rs[i] = a[i] - ls[i];
        }
    }

    return ls[n] == 0;
}

int main() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << a[1] << '\n';
            continue;
        }

        a[n + 1] = a[1];
        int L = 0, R = 0, M;
        for (int i = 1; i <= n; i++) {
            L = max(L, a[i] + a[i + 1]);
        }

        if (n & 1) {
            for (int i = 1; i <= n; i++) {
                R = max(R, a[i] * 3);
            }

            while (L < R) {
                M = L + (R - L) / 2;
                if (canGive(M)) {
                    R = M;
                } else {
                    L = M + 1;
                }
            }
        }

        cout << L << '\n';
    }
}
