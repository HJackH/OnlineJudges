#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL INF = 1e18;
const int MAXN = 4000 + 5;

struct Item {
    int id;
    int at;
    bool operator < (const Item &other) const {
        return at < other.at;
    }
};

int n, m;
Item a[MAXN], b[MAXN];
LL dp[MAXN][MAXN];
int from[MAXN][MAXN];
int in[MAXN];

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].at;
            a[i].id = i;
            dp[0][i] = INF;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i].at;
            b[i].id = i;
            dp[i][0] = INF;
        }
        dp[0][0] = 0;
        from[0][0] = -1;

        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i > j) {
                    dp[i][j] = INF;
                    continue;
                }
                dp[i][j] = abs(b[i].at - a[j].at);
                if (dp[i - 1][j - 1] < dp[i][j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                    from[i][j] = 0;
                } else {
                    dp[i][j] += dp[i][j - 1];
                    from[i][j] = 1;
                }
            }
        }

        for (int x = m, y = n; from[x][y] != -1; y--) {
            in[a[y].id] = b[x].id;
            if (from[x][y] == 0) {
                x--;
            }
        }

        cout << dp[m][n] << "\n";
        for (int i = 1; i <= n; i++) {
            cout << in[i] << " \n"[i == n];
        }
    }
}