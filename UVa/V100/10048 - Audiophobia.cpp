#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 100 + 5;

int n, m, q;
int G[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
            }
        }
    }
}

int main() {
    int kase = 0;
    while (cin >> n >> m >> q && (n || m || q)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = INF;
            }
        }
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }

        floyd();

        if (kase != 0) {
            cout << "\n";
        }
        cout << "Case #" << ++kase << "\n";
        while (q--) {
            cin >> u >> v;
            if (G[u][v] == INF) {
                cout << "no path\n";
            } else {
                cout << G[u][v] << "\n";
            }
        }
    }
}