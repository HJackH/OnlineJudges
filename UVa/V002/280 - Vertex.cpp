#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int n, cnt, vis[MAXN];
vector<int> G[MAXN];

void dfs(int u) {
    for (int v : G[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            cnt++;
            dfs(v);
        }
    }
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }

        int from, to;
        while (cin >> from && from) {
            while (cin >> to && to) {
                G[from].push_back(to);
            }
        }

        int q, st;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> st;
            memset(vis, 0, sizeof(vis));
            cnt = 0;
            dfs(st);

            cout << n - cnt;
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    cout << ' ' << j ;
                }
            }
            cout << '\n';
        }
    }
}