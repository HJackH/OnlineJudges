#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int INF = 1e9;
const int MAXN = 1000 + 5;

struct Edge {
    int v;
    int w;
};

struct Car {
    int v;
    int rem;
    int cost;
    bool operator < (const Car &other) const {
        return cost > other.cost;
    }
};

int n, m;
int price[MAXN], dp[MAXN][100 + 5];
vector<Edge> G[MAXN];

int dijk(int st, int ed, int c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = INF;
        }
    }

    priority_queue<Car> pq;
    pq.push({st, 0, 0});
    dp[st][0] = 0;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (now.v == ed && now.rem == 0) {
            return now.cost;
        }   
        if (dp[now.v][now.rem] < now.cost) {
            continue;
        }
        for (auto &e : G[now.v]) {
            if (e.w > now.rem) {
                continue;
            }
            if (dp[e.v][now.rem - e.w] > now.cost) {
                dp[e.v][now.rem - e.w] = now.cost;
                pq.push({e.v, now.rem - e.w, dp[e.v][now.rem - e.w]});
            }
        }
        if (now.rem + 1 <= c && dp[now.v][now.rem + 1] > now.cost + price[now.v]) {
            dp[now.v][now.rem + 1] = now.cost + price[now.v];
            pq.push({now.v, now.rem + 1, dp[now.v][now.rem + 1]});
        }
    }
    return INF;
}

int main() { IOS
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> price[i];
            G[i].clear();
        }

        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            G[u].pb({v, w});
            G[v].pb({u, w});
        }

        int q, c, st, ed;
        cin >> q;
        while (q--) {
            cin >> c >> st >> ed;
            int ans = dijk(st, ed, c);
            if (ans == INF) {
                cout << "impossible\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
}