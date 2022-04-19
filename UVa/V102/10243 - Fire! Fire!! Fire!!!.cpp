#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1000 + 5;

int n, dp[MAXN][2];
vector<int> G[MAXN];

void dfs(int u, int from) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int v : G[u]) {
        if (v == from) {
            continue;
        }
        dfs(v, u);
        dp[u][1] += min(dp[v][0], dp[v][1]);
        dp[u][0] += dp[v][1];
    }
}

int main() { IOS
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1, k, x; i <= n; i++) {
            cin >> k;
            while (k--) {
                cin >> x;
                G[i].pb(x);
            }
        }
        dfs(1, -1);
        cout << max(1, min(dp[1][0], dp[1][1])) << "\n";
    }
}
