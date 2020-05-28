#include <bits/stdc++.h>
using namespace std;

int T, n, len, tmp;

int main() {
    cin >> T;
    while (T--) {
        cin >> len >> n;
        int ansMin = -2147483648, ansMax = -2147483648;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            ansMin = max(ansMin, min(tmp, len - tmp));
            ansMax = max(ansMax, max(tmp, len - tmp));
        }
        cout << ansMin << ' ' << ansMax << '\n';
    }
}