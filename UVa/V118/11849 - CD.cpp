#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9;

int n, m, tmp;
bitset<MAXN + 5> S;

int main() {
    while (cin >> n >> m && (n || m)) {
        S.reset();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            S.set(tmp);
        }
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            if (S.test(tmp)) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}