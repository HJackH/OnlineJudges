#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 10;

int T, n, a[MAXN];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);

        int ans = 0, med;
        if (n & 1) {
            med = a[(n - 1) /2];
        } else {
            med = (a[n / 2 - 1] + a[n / 2]) / 2; 
        }
        for (int i = 0; i < n; i++) {
            ans += abs(med - a[i]);
        }

        cout << ans << endl;
    }
}
