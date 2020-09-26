#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOS

    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;

        int ans = 0;
        while (a <= n && b <= n) {
            if (a > b) {
                b += a;
            } else {
                a += b;
            }
            ++ans;
        }
        cout << ans << '\n';
    }
}