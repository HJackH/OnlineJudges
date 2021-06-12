#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())
const int MAXN = 1e4 + 5;

int n, m;
int vy[MAXN], my[MAXN];
vector<int> G[MAXN];

bool match(int u) {
    for (int v : G[u]) {
        if (vy[v]) {
            continue;
        }
        vy[v] = true;
        if (my[v] == -1 || match(my[v])) {
            my[v] = u;
            return true;
        }
    }
    return false;
}

bool KM() {
    for (int i = 0; i < n; i++) {
        my[i] = -1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        memset(vy, 0, sizeof(vy));
        if (match(i)) {
            cnt++;
        }
    }
    return cnt == n;
}

int main() { IOS
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            G[u].pb(v);
        }
        cout << (KM() ? "YES" : "NO") << "\n";
    }
}