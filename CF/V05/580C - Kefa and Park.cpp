#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e5 + 5;

int n, m, a[MAXN], ans;
vector<int> G[MAXN];

void dfs(int u, int from, int cnt) {
    if (cnt > m) {
        return;
    }

    if (G[u].size() == 1 && u != 0) {
        ++ans;
        return;
    }

    for (int v : G[u]) {
        if (v != from) {
            if (a[v]) {
                dfs(v, u, cnt + 1);
            } else {
                dfs(v, u, 0);
            }
        }
    }
}

int main() {
    IOS

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    G[0].pb(1);
    G[1].pb(0); 
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    
    ans = 0;
    dfs(0, -1, 0);
    cout << ans << '\n';
}