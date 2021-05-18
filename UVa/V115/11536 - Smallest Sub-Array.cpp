#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 1e6 + 5;
const int MAXK = 101 + 5;

int n, m, k;
int a[MAXN] = {0, 1, 2, 3}, have[MAXK];

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> m >> k;
        for (int i = 4; i <= n; i++) {
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
        }

        memset(have, 0, sizeof(have));
        int ans = INF, cnt = 0, l = 1, r = 1;
        while (r <= n) {
            if (a[r] <= k) {
                if (!have[a[r]]) {
                    cnt++;
                }
                have[a[r]]++;
            }
            while (l <= r && cnt == k) {
                if (a[l] <= k) {
                    if (have[a[l]] == 1) {
                        cnt--;
                    }
                    have[a[l]]--;
                }
                ans = min(ans, r - l + 1);
                l++;
            }
            r++;
        }

        cout << "Case " << kase << ": ";
        if (ans == INF) {
            cout << "sequence nai\n";
        } else {
            cout << ans << "\n";
        }
    }
}