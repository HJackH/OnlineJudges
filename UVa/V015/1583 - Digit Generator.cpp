#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

int ans[MAXN + 100];

int main() {
    for (int i = MAXN; i >= 1; i--) {
        int sum = i, tmp = i;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        ans[sum] = i;
    }

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << ans[n] << "\n";
    }
}