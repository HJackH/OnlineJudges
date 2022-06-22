#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e6 + 7;
const int MAXN = 20 * 20;

int comb[MAXN + 5][MAXN + 5];

void build() {
    for (int i = 1; i <= MAXN; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

int main() {
    build();
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        int n, m, k;
        cin >> n >> m >> k;
        if (!k) {
            cout << "Case " << kase << ": 0\n";
            continue;
        }
        int ans = 0;
        for (int mask = 0, ed = 1 << 4; mask < ed; mask++) {
            int r = n, c = m, bits = 0;
            if (mask & 1) {
                c--;
                bits++;
            }
            if (mask & 2) {
                c--;
                bits++;
            }
            if (mask & 4) {
                r--;
                bits++;
            }
            if (mask & 8) {
                r--;
                bits++;
            }
            if (bits & 1) {
                ans = (ans - comb[r * c][k] + MOD) % MOD;
            } else {
                ans = (ans + comb[r * c][k]) % MOD;
            }
        }
        cout << "Case " << kase << ": " << ans << "\n";
    }
}