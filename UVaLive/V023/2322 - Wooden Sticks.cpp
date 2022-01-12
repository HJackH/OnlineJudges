#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 5;

struct Stick {
    int l;
    int w;
    bool operator < (const Stick &other) const {
        if (l == other.l) {
            return w < other.w;
        }
        return l < other.l;
    }
};

int n;
Stick a[MAXN];
bool vis[MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].l >> a[i].w;
            vis[i] = 0;
        }
        sort(a, a + n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            ans++;
            int tw = a[i].w;
            for (int j = i + 1; j < n; j++) {
                if (!vis[j] && a[j].w >= tw) {
                    vis[j] = 1;
                    tw = a[j].w;
                }
            }
        }

        cout << ans << "\n";
    }
}