#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1000 + 5;

int n, s, k, boss[MAXN];
bool ok[MAXN];
vector<int> G[MAXN], lv[MAXN];

void dfs1(int u, int from, int d) {
    boss[u] = from;
    if (G[u].size() == 1) {
        lv[d].pb(u);
        return;
    }
    for (int v : G[u]) {
        if (v != from) {
            dfs1(v, u, d + 1);
        }
    }
}

void dfs2(int u, int from, int d) {
    ok[u] = 1;
    if (d == k) {
        return;
    }
    for (int v : G[u]) {
        if (v != from) {
            dfs2(v, u, d + 1);
        }
    }
}

int findk(int x) {
    for (int i = 0; i < k; i++) {
        x = boss[x];
    }
    return x;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s >> k;
        for (int i = 0; i <= n; i++) {
            G[i].clear();
            lv[i].clear();
            boss[i] = -1;
            ok[i] = 0;
        }
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }

        dfs1(s, -1, 0);

        int ans = 0;
        for (int l = n - 1; l > k; l--) {
            for (int i : lv[l]) {
                if (!ok[i]) {
                    int f = findk(i);
                    ans++;
                    dfs2(f, -1, 0);
                }
            }
        }

        cout << ans << '\n';
    }
}