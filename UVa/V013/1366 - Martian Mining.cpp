#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 500 + 5;

int n, m;
int y[MAXN][MAXN], b[MAXN][MAXN], dp[MAXN][MAXN];

int main() { IOS
    while (cin >> n >> m && (n || m)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> y[i][j];
                y[i][j] += y[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> b[i][j];
                b[i][j] += b[i - 1][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j] + y[i][j], dp[i][j - 1] + b[i][j]);
            }
        }

        cout << dp[n][m] << "\n";
    }
}