#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;

int n, gcdtable[MAXN + 5][MAXN + 5];

int main() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i + 1; j <= MAXN; j++) {
            gcdtable[i][j] = __gcd(i, j);
        }
    }

    while (cin >> n && n) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += gcdtable[i][j];
            }
        }
        cout << ans << '\n';
    }
}