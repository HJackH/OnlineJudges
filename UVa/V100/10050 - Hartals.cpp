#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 3650 + 5;

int n, p, h, day[MAXN];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> p;
        memset(day, 0, sizeof(day));
        for (int i = 0; i < p; i++) {
            cin >> h;
            for (int j = h; j <= n; j += h) {
                day[j] = 1;
            }
        }

        int ans = 0, now;
        for (int i = 1; i <= n; i++) {
            now = (i - 1) % 7;
            if (now == 5 || now == 6) {
                continue;
            }
            if (day[i]) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}