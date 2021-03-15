#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int INF = 1e9;
const int MAXN = 100 + 5;

struct Pos {
    int at;
    int cost;
    bool operator < (const Pos &other) const {
        return cost > other.cost;
    }
};

int n, ed, m, ti;
vector<Pos> G[MAXN];
int d[MAXN];

int sol(int st) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[st] = 0;

    priority_queue<Pos> pq;
    pq.push({ st, 0 });
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (u.at == ed) {
            return 1;
        }
        if (d[u.at] < u.cost) {
            continue;
        }
        for (auto &v : G[u.at]) {
            int tot = u.cost + v.cost;
            if (tot < d[v.at] && tot <= ti) {
                d[v.at] = u.cost + v.cost;
                pq.push({ v.at, d[v.at] });
            }
        }
    }
    return 0;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> ed >> ti >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }

        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            G[u].pb({ v, w });
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += sol(i);
        }
        cout << ans << '\n';
        if (T) {
            cout << '\n';
        }
    }
}