#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 100 + 10;

int C, S, Q, w[MAXN][MAXN], d[MAXN][MAXN];

void floyd() {
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            d[i][j] = w[i][j];
        }
    }

    for (int k = 1; k <= C; k++) {
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }
}

int main() {
    int kase = 0;
    cin >> C >> S >> Q;
    while (true) {
        for (int i = 0; i < C + 5; i++) {
            for (int j = 0; j < C + 5; j++) {
                w[i][j] = INF; 
            }
            w[i][i] = 0;
        }

        int from, to, we;
        for (int i = 0; i < S; i++) {
            cin >> from >> to >> we;
            w[from][to] = w[to][from] = we;
        }

        floyd();

        cout << "Case #" << ++kase << '\n';
        int st, ed;
        for (int i = 0; i < Q; i++) {
            cin >> st >> ed;
            if (d[st][ed] == INF) {
                cout << "no path\n";
            } else {
                cout << d[st][ed] << '\n';
            }
        }

        cin >> C >> S >> Q;
        if (C || S || Q) {
            cout << '\n';
        } else {
            break;
        }
    }
}