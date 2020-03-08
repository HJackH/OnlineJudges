#include <bits/stdc++.h>
using namespace std;

int T, n, c;

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c;
            ans = max(ans, c);
        }
        cout << "Case " << t << ": " << ans << endl;
    }
}
