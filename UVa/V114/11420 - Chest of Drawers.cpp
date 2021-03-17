#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 70;

int n, s;
LL dp[MAXN + 5][MAXN + 5][2];

LL sol(int i, int j, int k) {
    if (i < 0 || i > MAXN || j < 0 || j > MAXN || j > i) {
        return 0;
    }
    auto &ans = dp[i][j][k];
    if (ans != -1) {
        return ans;
    }
    if (!k) {
        return ans = sol(i - 1, j + 1, 1) + sol(i - 1, j, 0);
    } else {
        return ans = sol(i - 1, j - 1, 1) + sol(i - 1, j - 1, 0);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[1][0][0] = dp[1][1][1] = 1;
    while (cin >> n >> s && (n >= 0 || s >= 0)) {
        cout << sol(n, s, 1) + sol(n, s, 0) << '\n';
    }
}