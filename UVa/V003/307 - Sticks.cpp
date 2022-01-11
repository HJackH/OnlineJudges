#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int n, a[MAXN];
bool vis[MAXN];
int sum_len, total_cnt, ans;

bool dfs(int i, int now_len, int cnt) {
    if (now_len == ans) {
        cnt++;
        now_len = 0;
        i = -1;
    }
    if (cnt == total_cnt) {
        return true;
    }
    for (int j = i + 1; j < n; j++) {
        if (vis[j]) {
            continue;
        }
        // vis[0] always = true, won't RE!
        if (a[j] == a[j - 1] && !vis[j - 1]) {
            continue;
        }
        if (now_len + a[j] > ans) {
            continue;
        }
        vis[j] = 1;
        if (dfs(j, now_len + a[j], cnt)) {
            return true;
        }
        vis[j] = 0;
        if (now_len == 0) {
            return false;
        }
    }
    return false;
}

int main() {
    while (cin >> n && n) {
        sum_len = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum_len += a[i];
        }

        sort(a, a + n, greater<int>());

        for (ans = a[0]; ans <= sum_len / 2; ans++) {
            if (sum_len % ans != 0) {
                continue;
            }
            memset(vis, 0, sizeof(vis));
            total_cnt = sum_len / ans;
            vis[0] = 1;
            if (dfs(0, a[0], 0)) {
                cout << ans << "\n";
                break;
            }
        }

        if (ans > sum_len / 2) {
            cout << sum_len << "\n";
        }
    }
}