#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n, r[MAXN];

int main() {
    IOS

    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
        }

        int ans = 0;
        for (int i = n; i >= 1; i--) {
            if (ans < (r[i] - r[i - 1])) {
                ans = r[i] - r[i - 1];
            } else if (ans == (r[i] - r[i - 1])) {
                ++ans;
            }
        }
        cout << "Case " << kase << ": " << ans << '\n';
    }
}