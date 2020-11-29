#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int INF = 1e9;
const int MAXN = 50 + 5;

int n, l, c[MAXN], dp[MAXN][MAXN];

int solve(int x, int y) {
    auto &ans = dp[x][y];
    if (ans > -1) {
        return ans;
    }
    if (x + 1 == y) {
        return ans = 0;
    }
    ans = INF;

    //find cutting point with minimum cost
    for (int m = x; m < y; m++) {
        ans = min(ans, solve(x, m) + solve(m, y));
    }
    return ans = ans + c[y] - c[x];
}

int main() { IOS
    while (cin >> l && l) {
        cin >> n;
        c[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        c[++n] = l;
        memset(dp, -1, sizeof(dp));
        cout << "The minimum cutting is " << solve(0, n) << ".\n";
    }
}