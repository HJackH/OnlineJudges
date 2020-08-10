#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e6 + 5;

int n, dp[MAXN];

int f91(int x) {
    if (dp[x]) {
        return dp[x];
    }
    if (x >= 101) {
        return dp[x] = x - 10;
    }
    return dp[x] = f91(f91(x + 11));
}

int main() {
    IOS
    while (cin >> n && n) {
        cout << "f91(" << n << ") = " << f91(n) << '\n';
    }
}