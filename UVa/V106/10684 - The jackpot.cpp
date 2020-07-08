#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int n, a[MAXN];

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum = max(sum + a[i], 0);
            ans = max(ans, sum);
        }

        if (ans > 0) {
            cout << "The maximum winning streak is " << ans << ".\n";
        } else {
            cout << "Losing streak.\n";
        }
    }
}