#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 100 + 10;

int n, a[MAXN][MAXN], s[MAXN][MAXN];

int main() {
    while (cin >> n) {
        memset(s, 0, sizeof(s));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                s[i][j] = a[i][j] +  s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
            }
        }

        int ans = -INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = i; k <= n; k++) {
                    for (int l = j; l <= n; l++) {
                        int tmps = s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1];
                        ans = max(ans, tmps);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
