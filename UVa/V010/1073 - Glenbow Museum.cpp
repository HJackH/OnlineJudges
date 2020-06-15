#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n;
long long dp[MAXN + 5][5][2], ans[MAXN + 5];

int main() {
    for (int k = 0; k < 2; k++) {
        dp[1][0][k] = 1;
        for (int i = 2; i < MAXN; i++) {
            for (int j = 0; j < 5; j++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k];
                }
            }
        }
    }

    for (int i = 1; i <= MAXN; i++) {
        if (i < 4 || i % 2) {
            ans[i] = 0;
        } else {
            int R = (i + 4) / 2;
            ans[i] = dp[R][3][0] + dp[R][4][1] + dp[R][4][0];
        }
    }

    int kase = 0;
    while (cin >> n && n) {
        cout << "Case " << ++kase << ": " << ans[n] << '\n';
    }
}