#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int n, m, num;
int par[MAXN][MAXN], place[MAXN], group[2 + 5];

void solve() {
    for (int i = 1; i <= n; i++) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = 1; j <= n; j++) {
            if (par[i][j]) {
                if (place[j] == 1) {
                    tmp1++;
                } else if (place[j] == 2) {
                    tmp2++;
                }
            }
        }

        if (tmp1 > tmp2) {  //put in group2
            place[i] = 2;
            group[2]++;
            num += tmp2;
        } else {            //put in group1
            place[i] = 1;
            group[1]++;
            num += tmp1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        memset(par, 0, sizeof(par));
        memset(place, 0, sizeof(place));
        memset(group, 0, sizeof(group));
        num = 0;

        cin >> n >> m;

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            par[a][b] = par[b][a] = 1;
        }

        solve();

        cout << "Case #" << kase << ": ";
        if (num > m / 2) {
            cout << "Impossible.\n\n";
            continue;
        }
        cout << group[1] << '\n';
        for (int i = 1; i <= n; i++) {
            if (place[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}