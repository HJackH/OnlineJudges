#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int x, y;

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y;

        int ans = 0, step = 1;
        while ((y - x) > step) {
            y -= step;
            x += step;
            ans += 2;
            ++step;
        }
        if (x < y) {
            ++ans;
        }
        cout << ans << '\n';
    }
}