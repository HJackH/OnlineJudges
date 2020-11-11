#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1000;

vector<vector<int>> dp(MAXN + 5, vector<int>(3, 0));

int main() { IOS
    dp[3][0] = 1;
    dp[5][1] = 1;
    dp[7][2] = 1;
    for (int i = 1; i <= MAXN; i++) {
        if (!(dp[i][0] + dp[i][1] + dp[i][2])) {
            continue;
        }
        for (int j = 0; j < 3; j++) {
            // 3, 5, 7
            int len = 2 * j + 3;
            for (int k = i + len, cnt = 1; k <= MAXN; k += len, cnt++) {
                if (dp[k][0] + dp[k][1] + dp[k][2]) {
                    break;
                } 
                for (int l = 0; l < 3; l++) {
                    dp[k][l] = dp[i][l] + (l == j) * cnt;
                }
            }
        }
    }

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        
        if (dp[n][0] + dp[n][1] + dp[n][2]) {
            cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << '\n';
        } else {
            cout << "-1\n";
        }
    }
}