#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 20 + 5;

int n, ans[MAXN], b[MAXN], dp[MAXN][MAXN];

int main() { IOS
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        ans[x] = i;
    }

    string s;
    cin.ignore();
    while (getline(cin, s)) {
        stringstream ss(s);
        for (int i = 1, x; i <= n && ss >> x; i++) {
            b[x] = i;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[n][n] << '\n';
    }
}