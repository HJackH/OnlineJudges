#include <iostream>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200 + 5;

int n, m, ind[MAXN], G[MAXN][MAXN], ans[MAXN];

bool rTopo() {
    for (int ball = n; ball >= 1; ball--) {
        bool ok = false;
        for (int w = n; w >= 1; w--) {
            if (!ind[w]) {  //ind == 0 && not vis
                ans[w] = ball;
                ind[w]--;   //vis = true
                for (int j = 1; j <= n; j++) {
                    if (G[w][j]) {
                        ind[j]--;
                    }
                }
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            ind[i] = 0;
            for (int j = 1; j <= n; j++) {
                G[i][j] = 0;
            }
        }
        int a, b;
        while (m--) {
            cin >> a >> b;
            if (!G[b][a]) {
                G[b][a] = 1;
                ind[a]++;
            }
        }

        if (rTopo()) {
            for (int i = 1; i <= n; i++) {
                cout << ans[i];
                if (i != n) {
                    cout << ' ';
                }
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}