#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1000 + 5;

string s;
int dp[MAXN][MAXN];

int sol(int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s[i] == s[j]) {
        return dp[i][j] = sol(i + 1, j - 1);
    }
    return dp[i][j] = min(sol(i, j - 1), min(sol(i + 1, j - 1), sol(i + 1, j))) + 1;
}

int main() { IOS
    int T, kase = 0;
    cin >> T;
    while (T--) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++kase << ": " << sol(0, s.length() - 1) << '\n';
    }
}