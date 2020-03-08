#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, b, h, w, p, a;

int main() {
    while (cin >> n >> b >> h >> w) {
        int ans = INF;
        for (int i = 0; i < h; i++) {
            cin >> p;
            for (int j = 0; j < w; j++) {
                cin >> a;
                if (a >= n && n * p <= b) {
                    ans = min(ans, n * p);
                }
            }
        }

        if (ans == INF) {
            cout << "stay home" << endl;
        } else {
            cout << ans << endl;
        }
    }
}
