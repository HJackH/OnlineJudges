#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 500 + 5;

int n, m;
int G[MAXN][MAXN];

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> m;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                G[i][j] = INF;
            }
            G[i][i] = 0;
        }

        int u, v, cnt = n;
        while (m--) {
            cin >> u >> v;
            G[u][cnt] = G[cnt][u] = G[v][cnt] = G[cnt][v] = 1;
            cnt++;
        }

        for (int k = 0; k < cnt; k++) {
            for (int i = 0; i < cnt; i++) {
                for (int j = 0; j < cnt; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < cnt; i++) {
            sort(G[i], G[i] + n);
            ans = min(ans, G[i][n - 1] + G[i][n - 2]);
        }

        cout << "Case #" << kase << ":\n" << ans / 2 << "\n\n";
    }
}