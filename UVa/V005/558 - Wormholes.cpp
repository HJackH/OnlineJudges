#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1000;

struct Edge {
    int at;
    long long cost;
};

int n, m;
long long dis[MAXN];
vector<Edge> G[MAXN];

void init() {
    for (int i = 0; i < n; i++) {
        G[i].clear();
        dis[i] = INF;
    }
}

bool SPFA(int st) {
    vector<int> cnt(n, 0);
    vector<bool> inq(n, false);
    queue<int> q;

    q.push(st);
    dis[st] = 0;
    inq[st] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inq[now] = false;
        for (auto &e : G[now]) {
            if (dis[e.at] > dis[now] + e.cost) {
                dis[e.at] = dis[now] + e.cost;
                if (!inq[e.at]) {
                    cnt[e.at]++;
                    if (cnt[e.at] > n) {
                        return false;
                    }
                    inq[e.at] = true;
                    q.push(e.at);
                }
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        int x, y, t;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            G[x].push_back({y, t});
        }
        if (!SPFA(0)) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }
}