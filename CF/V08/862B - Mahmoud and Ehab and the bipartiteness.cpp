#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n, lb[MAXN], cnt[2];
vector<int> G[MAXN];

void dfs(int u, int pre, int val) {
    ++cnt[lb[u] = val];
    for (int v : G[u]) {
        if (v != pre) {
            dfs(v, u, val ^ 1);
        }
    }
}

int main() {
    IOS

    cin >> n;
    
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0, 0);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (lb[i]) {
            ans += cnt[0] - G[i].size();
        }
    }
    cout << ans << '\n';
}