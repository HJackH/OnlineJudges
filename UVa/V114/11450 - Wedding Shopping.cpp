#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())
const int MAXM = 200 + 5;
const int MAXC = 20 + 5;

int m, c, dp[MAXC][MAXM];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> m >> c;
        dp[0][0] = 1;
        for (int i = 1; i <= c; i++) {
            int k, n;
            cin >> k;
            while (k--) {
                cin >> n;
                for (int j = n; j <= m; j++) {
                    if (dp[i - 1][j - n]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        int ans = -1;
        for (int i = m; i >= 0; i--) {
            if (dp[c][i]) {
                ans = i;
                break;
            }
        }

        if (ans == -1) {
            cout << "no solution\n";
        } else {
            cout << ans << "\n";
        }
    }
}