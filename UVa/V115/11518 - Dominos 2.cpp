#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e4 + 5;

int n, m, l;
vector<int> G[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> l;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            vis[i] = 0;
        }
        for (int i = 0, x, y; i < m; i++) {
            cin >> x >> y;
            G[x].pb(y);
        }
        for (int i = 0, z; i < l; i++) {
            cin >> z;
            dfs(z);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += vis[i];
        }
        cout << ans << '\n';
    }
}