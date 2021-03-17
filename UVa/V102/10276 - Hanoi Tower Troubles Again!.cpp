#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 50 + 5;

int n, ans, p[MAXN];

bool chk(int a, int b) {
    int sum = a + b;
    int sq = round(sqrt(sum));
    return sq * sq == sum;
}

void sol(int num) {
    for (int i = 0; i < n; i++) {
        if (!p[i] || chk(p[i], num)) {
            p[i] = num;
            ans = max(ans, num);
            sol(num + 1);
            return;
        }
    }
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(p, 0, sizeof(p));
        ans = 0;
        sol(1);
        cout << ans << '\n';
    }
}