#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1000 + 5;

int n, m, c[MAXN];

bool chk(int limit) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i];
        if (sum > limit) {
            sum = c[i];
            cnt++;
        }
    }
    return cnt < m;
}

int main() { IOS
    while (cin >> n >> m) {
        int L = 0, R = 0;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            L = max(L, c[i]);
            R += c[i];
        }

        while (L < R) {
            int mid = (L + R) / 2;
            if (chk(mid)) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << R << "\n";
    }
}