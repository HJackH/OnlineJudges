#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

int n, dp[MAXN][MAXN];
string input, tmp;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, input);
        n = input.length();
        tmp = input;
        reverse(tmp.begin(), tmp.end());

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (input[i - 1] == tmp[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << dp[n][n] << '\n';
    }
}