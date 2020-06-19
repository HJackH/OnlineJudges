#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m, rainOn[MAXN], nRain[MAXN], ans[MAXN], lake[MAXN];

int find(int x) {
    if (x == nRain[x]) {
        return x;
    }
    return nRain[x] = find(nRain[x]);
}

bool solve() {
    for (int i = 1; i <= m; i++) {
        if (!rainOn[i]) {
            continue;
        }

        int x = find(lake[rainOn[i]]);
        if (x <= i) {
            ans[x] = rainOn[i];
            nRain[x] = find(x + 1);
        } else {
            return false;
        }
        lake[rainOn[i]] = i;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> rainOn[i];
        }

        int last = m + 1;
        nRain[m + 1] = m + 1;
        for (int i = m; i >= 0; i--) {
            if (!rainOn[i] && i != 0) {
                last = i;
            }
            nRain[i] = last;
        }

        memset(ans, 0, sizeof(ans));
        memset(lake, 0, sizeof(lake));
        if (solve()) {
            cout << "YES\n";
            for (int i = 1; i <= m; i++) {
                if (!rainOn[i]) {
                    cout << ans[i] << ' ';
                }
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}