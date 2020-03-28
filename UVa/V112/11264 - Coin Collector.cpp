#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;

int T, n;
long long a[MAXN];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = a[0];
        int ans = 2;
        for (int i = 1; i < n - 1; i++) {
            if (sum + a[i] < a[i + 1]) {
                sum += a[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
