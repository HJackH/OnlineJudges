#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4000 + 5;

int n, a[MAXN + 5], dp[MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dq.push_front(a[i]);
            dq.push_back(a[i]);
        }

        n *= 2;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dq[j] > dq[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }
}