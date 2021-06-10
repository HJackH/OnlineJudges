#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) (int((x).size()))
const int MAXN = 2e5 + 5;

int n, m;

int main() { IOS
    cin >> n >> m;
    int now = 0;
    LL ans = 0;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        x--;
        ans += (x - now + n) % n;
        now = x;
    }
    cout << ans << "\n";
}