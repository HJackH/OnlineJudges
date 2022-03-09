#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ans = 0;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        ans = max(ans, x + y);
    }
    cout << ans << "\n";
}