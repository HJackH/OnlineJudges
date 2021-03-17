#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e4 + 5;

int n, dp[MAXN][2];
bool vis[MAXN];
vector<int> G[MAXN];

void dfs(int u, int from) {
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int v : G[u]) {
        if (!vis[v] && v != from) {
            dfs(v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

int main() { IOS
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            G[i].clear();
            int m, to;
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> to;
                G[i].pb(to);
            }
        }   
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, -1);
                ans += max(min(dp[i][0], dp[i][1]), 1);
            }
        }
        cout << ans << '\n';
    }
}