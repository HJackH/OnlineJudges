#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;

long long n, k, m, dp[MAXN + 5][MAXN + 5];

int main() {
    while (cin >> n >> k >> m) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                for (int t = 1; t <= m && j - t >= 0; t++) {
                    dp[i][j] += dp[i - 1][j - t];
                }
            }
        }
        cout << dp[k][n] << '\n';
    }
}