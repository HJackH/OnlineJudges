#include <bits/stdc++.h>
using namespace std;

int n, tmp;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int maxn = 0, minn = 150;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            maxn = max(maxn, tmp);
            minn = min(minn, tmp);
        }
        cout << 2 * (maxn - minn) << '\n';
    }
}