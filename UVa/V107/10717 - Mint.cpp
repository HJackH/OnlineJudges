#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;
const long long INF = 1e18;

int n, t;
long long a[MAXN];

long long lcm(long long x, long long y) {
    return (x * y) / __gcd(x, y);
}

int main() {
    while (cin >> n >> t && (n || t)) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long q, ans1, ans2;
        while (t--) {
            cin >> q;
            ans1 = -INF;
            ans2 = INF;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long long lcm1 = lcm(a[i], a[j]);
                    for (int k = j + 1; k < n; k++) {
                        long long lcm2 = lcm(lcm1, a[k]);
                        for (int l = k + 1; l < n; l++) {
                            long long lcm3 = lcm(lcm2, a[l]);
                            ans1 = max(ans1, (q / lcm3) * lcm3);
                            ans2 = min(ans2, ((q + lcm3 - 1) / lcm3) * lcm3);
                        }
                    }
                }
            }
            cout << ans1 << ' ' << ans2 << '\n';
        }
    }
}