#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int INF = 1e9;
const int MAXN = 200 + 5;

struct Car {
    int st;
    int len;
};

int n, m, dp[MAXN][MAXN][2];
Car a[MAXN], b[MAXN];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        int total;
        cin >> total;

        n = m = 0;

        char side;
        for (int i = 0; i < total; i++) {
            cin >> side;
            if (side == 'A') {
                n++;
                cin >> a[n].st >> a[n].len;
            } else {
                m++;
                cin >> b[m].st >> b[m].len;
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = dp[i][j][1] = INF;
            }
        }

        dp[0][0][0] = dp[0][0][1] = 0; 
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int t1 = dp[i][j][1], t2 = 0;
                for (int k = i + 1; k <= n; k++) {
                    t1 = max(t1, a[k].st);
                    t2 = max(t2, t1 + a[k].len);
                    dp[k][j][0] = min(dp[k][j][0], t2);
                    t1 += 10;
                    t2 += 10;
                }
                t1 = dp[i][j][0], t2 = 0;
                for (int k = j + 1; k <= m; k++) {
                    t1 = max(t1, b[k].st);
                    t2 = max(t2, t1 + b[k].len);
                    dp[i][k][1] = min(dp[i][k][1], t2);
                    t1 += 10;
                    t2 += 10;
                }
            }
        }

        cout << min(dp[n][m][0], dp[n][m][1]) << "\n";
    }
}