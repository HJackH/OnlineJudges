#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = (1 << 15) + 5;

vector<int> p;

void table() {
    vector<bool> vis(MAXN + 5, 0);
    for (int i = 2; i <= MAXN; i++) {
        if (!vis[i]) {
            p.pb(i);
        }
        for (int &j : p) {
            if (i * j > MAXN) {
                break;
            }
            vis[i * j] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}

int main() { IOS
    table();

    int n;
    while (cin >> n && n) {
        int ans = 0;
        for (int i : p) {
            if (i > n / 2) {
                break;
            }
            if (binary_search(p.begin(), p.end(), n - i)) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}