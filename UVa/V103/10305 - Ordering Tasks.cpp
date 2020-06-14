#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5; 

int n, m, vis[MAXN];
vector<int> G[MAXN];
vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    for (int u : G[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}

int main() {
    while (cin >> n >> m && (n || m)) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            G[a].push_back(b);
        }

        memset(vis, 0, sizeof(vis));
        ans.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
            if (i != 0) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}