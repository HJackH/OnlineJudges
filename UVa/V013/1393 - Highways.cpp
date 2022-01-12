#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 5;

int n, m;
int dp[MAXN][MAXN], tot[MAXN][MAXN];

int main() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + (__gcd(i, j) == 1);
            tot[i][j] = tot[i][j - 1] + tot[i - 1][j] - tot[i - 1][j - 1] + dp[i][j] - dp[i / 2][j / 2];
        }
    }
    while (cin >> n >> m && (n || m)) {
        cout << tot[n - 1][m - 1] * 2 << "\n";
    }
}