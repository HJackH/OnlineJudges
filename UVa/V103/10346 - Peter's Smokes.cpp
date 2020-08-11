#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n, k;

int main() {
    IOS
    while (cin >> n >> k) {
        int ans = n, trash = n;
        while (trash >= k) {
            ans += trash / k;
            trash = trash / k + trash % k;
        }
        cout << ans << '\n';
    }
}