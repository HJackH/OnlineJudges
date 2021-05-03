#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int n;
map<int, int> mp;
vector<vector<int>> G;
vector<int> in, vis;

int id(int x) {
    if (mp.count(x)) {
        return mp[x];
    }
    vector<int> vt;
    G.pb(vt);
    in.pb(0);
    vis.pb(0);
    return mp[x] = n++;
}

void add_edge(int a, int b) {
    a = id(a);
    b = id(b);
    G[a].pb(b);
    in[b]++;
}

bool dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (vis[v] || !dfs(v)) {
            return false;
        }
    }
    return true;
}

int main() { IOS
    int a, b, kase = 0;
    while (cin >> a >> b && (a >= 0 && b >= 0)) {
        n = 0;
        mp.clear();
        G.clear();
        in.clear();
        vis.clear();

        while (a || b) {
            add_edge(a, b);
            cin >> a >> b;
        }

        int rtcnt = 0, viscnt = 0;
        bool ans = 1;
        for (int i = 0; i < n; i++) {
            if (!in[i]) {
                rtcnt++;
                ans &= dfs(i);
            }
        }
        for (int i = 0; i < n; i++) {
            viscnt += vis[i];
        }

        cout << "Case " << ++kase << " is ";
        if ((n && rtcnt != 1) || viscnt != n || !ans) {
            cout << "not ";
        }
        cout << "a tree.\n";
    }
}