#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 3000 + 5;

int n, a[MAXN], b[MAXN];

int main() {
    IOS
    while (cin >> n && n) {
        int num;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> num;
            b[num] = i;
        }
        int ans = 0, l, r, len;
        for (int i = 0; i < n; i++) {
            l = r = b[a[i]];
            len = 1;
            for (int j = i + 1; j < n; j++) {
                l = min(l, b[a[j]]);
                r = max(r, b[a[j]]);
                if (r - l + 1 == ++len) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}