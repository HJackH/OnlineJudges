#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
const int INF = 1e9;

int G[MAXN][MAXN], kase = 0, n, pairs;
double sum;
map<int, int> M;

void init() {
    M.clear();
    n = 0;
    sum = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    int a, b;
    while (cin >> a >> b && a && b) {
        init();

        do {
            if (M.count(a) == 0) {
                M[a] = ++n;
            }
            if (M.count(b) == 0) {
                M[b] = ++n;
            }

            G[M[a]][M[b]] = 1;
        } while (cin >> a >> b && a && b);

        floyd();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum += G[i][j];
            }
        }

        pairs = n * (n - 1);
        cout << "Case " << ++kase << ": average length between pages = ";
        printf("%.3lf clicks\n", sum / (double)pairs);
    }
}
