#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e5 + 5; 

int n, m, a[MAXN];

bool chk(int len) {
    int cnt = 0, r = -1;
    for (int i = 0; i < m; i++) {
        if (r < a[i]) {
            cnt++;
            r = a[i] + 2 * len;
        }
    }
    return cnt <= n;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            a[i] *= 10;
        }

        sort(a, a + m);
        int l = 0, r = a[m - 1] - a[0];
        while (l < r) {
            int mid = (l + r) / 2;
            if (chk(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << (r / 10) << "." << (r % 10) << '\n';
    }
}