#include <bits/stdc++.h>
using namespace std;

int T, n;
map<int, int> M;

int main() {
    cin >> T;
    while (T--) {
        M.clear();
        cin >> n;

        int tmp, prev = 0, len = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (!M.count(tmp)) {
                len++;
                M[tmp] = i;
            } else {
                prev = max(M[tmp], prev);
                len = i - prev;
                M[tmp] = i;
            }
            ans = max(ans, len);
        }
        cout << ans << '\n';
    }
}