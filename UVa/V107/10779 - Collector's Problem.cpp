#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
const LL INF = 1e18;
const int MAXN = 50;

struct Edge {
    int to;
    LL cap;
    int rev;
    Edge(int v, LL c, int r) : to(v), cap(c), rev(r) {}
};

struct Dinic {
    int n;
    int level[MAXN], now[MAXN];
    vector<Edge> G[MAXN];
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
    }
    void add_edge(int u, int v, LL c) {
        G[u].eb(v, c, G[v].size());
        G[v].eb(u, 0, G[u].size() - 1);
    }
    bool bfs(int st, int ed) {
        fill(level, level + n + 1, -1);
        queue<int> q;
        q.push(st);
        level[st] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto &e : G[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[ed] != -1;
    }
    LL dfs(int u, int ed, LL limit) {
        if (u == ed) {
            return limit;
        }
        LL ret = 0;
        for (int &i = now[u]; i < G[u].size(); i++) {
            auto &e = G[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                LL f = dfs(e.to, ed, min(limit, e.cap));
                ret += f;
                limit -= f;
                e.cap -= f;
                G[e.to][e.rev].cap += f;
                if (!limit) {
                    return ret;
                }
            }
        }
        if (!ret) {
            level[u] = -1;
        }
        return ret;
    }
    LL flow(int st, int ed) {
        LL ret = 0;
        while (bfs(st, ed)) {
            fill(now, now + n + 1, 0);
            ret += dfs(st, ed, INF);
        }
        return ret;
    }
};

int main() { IOS
    Dinic dc;
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        int n, m;
        cin >> n >> m;
        dc.init(n + m + 1);

        int st = 1, ed = n + m + 1;
        int num[MAXN][MAXN] = {};
        for (int i = 1, ki; i <= n; i++) {
            cin >> ki;
            for (int j = 0, stk; j < ki; j++) {
                cin >> stk;
                ++num[i][stk];
            }
        }

        for (int i = 1; i <= m; i++) {
            dc.add_edge(st, i + n, num[1][i]);
            dc.add_edge(i + n, ed, 1);
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (num[i][j] > 1) {
                    dc.add_edge(i, j + n, num[i][j] - 1);
                } else if (num[i][j] == 0) {
                    dc.add_edge(j + n, i, 1);
                }
            }
        }

        cout << "Case #" << kase << ": " << dc.flow(st, ed) << '\n';
    }
}