#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 2e5 + 5;

int n, k, a[MAXN];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n, greater<int>());

        LL ans = a[0];
        for (int i = 1; i <= k; i++) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
}