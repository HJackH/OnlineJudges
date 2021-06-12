#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())
const int INF = 1e9;
const int MAXN = 100 + 5;
const int MAXK = 10 + 5;

struct Edge {
    int v;
    int w;
    int k;
    bool operator < (const Edge &other) const {
        if (w == other.w) {
            return k > other.k;
        }
        return w > other.w;
    }
};

int a, b, n, m, l, k;
int G[MAXN][MAXN];
int dp[MAXN][MAXK];

void floyd() {
    for (int k = 1; k <= a; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int dijk(int st, int ed) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i <= k; i++) {
        dp[st][i] = 0;
    }

    priority_queue<Edge> pq;
    pq.push({st, 0, 0});
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (now.v == ed) {
            return now.w;
        }
        if (dp[now.v][now.k] < now.w) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            auto &len = G[now.v][i];
            if (len == INF || i == now.v) {
                continue;
            }
            if (dp[i][now.k] > now.w + len) {
                dp[i][now.k] = now.w + len;
                pq.push({i, dp[i][now.k], now.k});
            }
            if (len <= l && now.k < k) {
                if (dp[i][now.k + 1] > now.w) {
                    dp[i][now.k + 1] = now.w;
                    pq.push({i, dp[i][now.k + 1], now.k + 1});
                }
            }
        }
    }
    
    return -1;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> m >> l >> k;
        n = a + b;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                G[i][j] = G[j][i] = INF;
            }
            G[i][i] = 0;
        }
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }

        floyd();

        cout << dijk(n, 1) << "\n";
    }
}