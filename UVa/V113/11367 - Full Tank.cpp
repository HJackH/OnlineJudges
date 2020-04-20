#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;
const int INF = 1e9;

struct Edge{
    int u;
    int v;
    int d;
};

struct Car{
    int on;
    int rem;
    int cost;
    bool operator < (const Car &other) const {
        return cost > other.cost;
    }
};

int n, m, price[MAXN], dp[MAXN][10000 + 50], c;
vector<Edge> G[MAXN];

int dijk(int from, int to) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = INF;
        }
    }

    priority_queue<Car> pq;
    pq.push((Car){from, 0, 0});
    dp[from][0] = 0;
    while (!pq.empty()) {
        auto i = pq.top();
        pq.pop();
        if (i.on == to && i.rem == 0) {
            return i.cost;
        }
        if (dp[i.on][i.rem] < i.cost) {
            continue;
        }
        for (auto j : G[i.on]) {
            if (c < j.d) {
                continue;
            }
            for (int k = j.d; k <= c; k++) {
                int addOil = k - i.rem > 0 ? k - i.rem : 0;
                if (dp[j.v][k - j.d] > addOil * price[i.on] + i.cost) {
                    dp[j.v][k - j.d] = addOil * price[i.on] + i.cost;
                    pq.push((Car){j.v, k - j.d, dp[j.v][k - j.d]});
                }
            }
        }
    }
    return INF;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> price[i];
            G[i].clear();
        }


        int a, b, d;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            G[a].push_back((Edge){a, b, d});
            G[b].push_back((Edge){b, a, d});
        }

        int q, s, e;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> c >> s >> e;
            int ans = dijk(s, e);
            if (ans == INF) {
                cout << "impossible\n";
            } else {
                cout << ans << '\n';
            }
        }
    }
}
