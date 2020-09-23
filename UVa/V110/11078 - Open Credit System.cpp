#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int INF = 1e9;

int n;

int main() {
    IOS
    
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = -INF, mx = -INF;
        for (int i = 0, tmp; i < n; i++) {
            cin >> tmp;
            ans = max(ans, mx - tmp);
            mx = max(mx, tmp);
        }
        cout << ans << '\n';
    }
}