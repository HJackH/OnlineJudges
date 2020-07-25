#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXW = 30 + 5;

struct Item {
    int p;
    int w;
};

int n, dp[MAXN][MAXW];
Item itemt;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> itemt.p >> itemt.w;
            for (int j = 0; j < MAXW; j++) {
                if (itemt.w > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - itemt.w] + itemt.p);
                }
            }
        }

        int G, mw, ans = 0;
        cin >> G;
        while (G--) {
            cin >> mw;
            ans += dp[n][mw];
        }
        cout << ans << '\n';
    }
}