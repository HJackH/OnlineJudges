#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 5;

int n;
int color[MAXN], cnt[MAXN];
int dp[MAXN][MAXN][MAXN];

int sol(int x, int y, int k) {
    if (x > y) {
        return 0;
    }
    int &ret = dp[x][y][k];
    if (ret != -1) {
        return ret;
    }
    ret = sol(x, y - 1, 0) + (cnt[y] + k) * (cnt[y] + k);
    for (int i = y - 1; i >= x; i--) {
        if (color[i] == color[y]) {
            ret = max(ret, sol(x, i, cnt[y] + k) + sol(i + 1, y - 1, 0));
        }
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        n = 0;
        int k, nowc = -1;
        cin >> k;
        for (int i = 0, x; i < k; i++) {
            cin >> x;
            if (x != nowc) {
                n++;
                nowc = x;
                color[n] = nowc;
                cnt[n] = 0;
            }
            cnt[n]++;
        }

        memset(dp, -1, sizeof(dp));
        cout << "Case " << kase << ": " << sol(1, n, 0) << "\n";
    }
}