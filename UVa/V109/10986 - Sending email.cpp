#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000 + 5;
const int INF = 1e9;

struct Edge {
    int at;
    int cost;
    bool operator < (const Edge &other) const {
        return cost > other.cost;
    }
};

int n, m;
int dis[MAXN];
vector<Edge> G[MAXN];

int dijk(int st, int ed) {
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
    }

    dis[st] = 0;
    priority_queue<Edge> pq;
    pq.push({st, 0});
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (now.at == ed) {
            return now.cost;
        }
        if (now.cost > dis[now.at]) {
            continue;
        }

        for (auto i : G[now.at]) {
            if (now.cost + i.cost < dis[i.at]) {
                dis[i.at] = now.cost + i.cost;
                pq.push({i.at, dis[i.at]});
            }
        }
    }
    return INF;
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        int s, t;
        cin >> n >> m >> s >> t;

        for (int i = 0; i < n; i++) {
            G[i].clear();
        }

        int a, b, w;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }

        int res = dijk(s, t);

        cout << "Case #" << kase << ": ";
        if (res == INF) {
            cout << "unreachable\n";
        } else {
            cout << res << '\n';
        }
    }
}