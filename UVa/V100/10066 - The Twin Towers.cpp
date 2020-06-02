#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int n1, n2, a1[MAXN], a2[MAXN], dp[MAXN][MAXN];

int main() {
    int kase = 0;
    while (cin >> n1 >> n2 && (n1 || n2)) {
        for (int i = 1; i <= n1; i++) {
            cin >> a1[i];
        }
        for (int i = 1; i <= n2; i++) {
            cin >> a2[i];
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (a1[i] == a2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << "Twin Towers #" << ++kase << "\nNumber of Tiles : " << dp[n1][n2] << "\n\n";
    }
}