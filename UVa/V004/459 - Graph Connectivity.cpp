#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 26;

vector<int> G[MAXN + 5];
bool vis[MAXN + 5];

void dfs(int u, int from) {
    vis[u] = 1;
    for (auto v : G[u]) {
        if (!vis[v] && v != from) {
            dfs(v, u);
        }
    }
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
            vis[i] = 0;
        }
        char st;
        string e;

        cin >> st;
        cin.ignore();
        while (getline(cin, e) && e.length()) {
            G[e[0] - 'A'].pb(e[1] - 'A');
            G[e[1] - 'A'].pb(e[0] - 'A');
        }

        int ans = 0;
        for (int i = st - 'A'; i >= 0; i--) {
            if (!vis[i]) {
                ++ans;
                dfs(i, -1);
            }
        }
        cout << ans << '\n';
        if (T) {
            cout << '\n';
        }
    }
}