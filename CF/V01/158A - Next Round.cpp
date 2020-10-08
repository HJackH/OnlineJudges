#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50 + 5;

int n, k, a[MAXN];

int main() {
    IOS

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[k - 1] && a[i] > 0) {
            ++ans;
        } else {
            break;
        }
    }
    cout << ans << '\n';
}