#include <bits/stdc++.h>
using namespace std;

int main() {

    int x, y, mx, my, ans;
    while (cin >> x >> y)
    {
        mx = min(x, y);
        my = max(x, y);
        ans = 0;
        for (int i = mx; i <= my; i++) {
            int cnt = 1, tmp = i;
            while (tmp != 1) {
                if (tmp & 1) {
                    tmp = 3 * tmp + 1;
                } else {
                    tmp /= 2;
                }
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << x << " " << y << " " << ans << endl;
    }
}