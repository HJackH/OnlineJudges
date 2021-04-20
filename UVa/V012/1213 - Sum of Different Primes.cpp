#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1120;
const int MAXK = 14;

int dp[MAXN + 5][MAXK + 5];
vector<int> primes;

void table() {
    vector<bool> vis(MAXN + 5, 0);
    for (int i = 2; i <= MAXN; i++) {
        if (!vis[i]) {
            primes.pb(i);
        }
        for (int j : primes) {
            if (i * j > MAXN) {
                break;
            }
            vis[i * j] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}

int main() { IOS
    table();
    dp[0][0] = 1;
    for (int p : primes) {
        for (int i = MAXN; i >= p; i--) {
            for (int j = 1; j <= MAXK; j++) {
                dp[i][j] += dp[i - p][j - 1];
            }
        }
    }

    int n, k;
    while (cin >> n >> k && (n || k)) {
        cout << dp[n][k] << '\n';
    }
}