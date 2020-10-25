#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 100 + 5;

int n;
bool vis[MAXN];
string s;

int main() { IOS
    int T, kase = 0;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.' && !vis[i]) {
                ++ans;
                for (int j = 0; j < 3 && i + j < n; j++) {
                    vis[i + j] = 1;
                }
            }
        }

        cout << "Case " << ++kase << ": " << ans << '\n';
    }
}