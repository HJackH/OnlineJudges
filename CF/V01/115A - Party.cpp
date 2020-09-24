#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 2000 + 5;

int n, d[MAXN];
vector<int> G[MAXN];

void dfs(int u) {
    for (auto v : G[u]) {
        if (!d[v]) {
            dfs(v);
        }
        d[u] = max(d[u], d[v]);
    }
    ++d[u];
}

int main() {
    IOS

    cin >> n;
    for (int i = 1, p; i <= n; i++) {
        cin >> p;
        if (p != -1) {
            G[p].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            dfs(i);
        }
        ans = max(ans, d[i]);
    }
    cout << ans << '\n';
}