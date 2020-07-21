#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25 + 5;

int n, m, ans;
bool vis[MAXN][MAXN];
vector<int> G[MAXN];

void dfs(int x, int depth) {
    ans = max(ans, depth);
    for (int v : G[x]) {
        if (!vis[x][v]) {
            vis[x][v] = vis[v][x] = 1;
            dfs(v, depth + 1);
            vis[x][v] = vis[v][x] = 0;
        }
    }
}

int main() {
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }

        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        ans = 0;
        for (int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            dfs(i, 0);
        }
        cout << ans << '\n';
    }
}