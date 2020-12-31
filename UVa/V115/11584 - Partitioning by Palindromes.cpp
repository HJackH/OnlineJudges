#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int INF = 1e9;
const int MAXN = 1e3 + 5;

string s;
int n, dp[MAXN];

bool isPa(int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.length();
        fill(dp + 1, dp + n + 1, INF);
        
        // i = l, j = r
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (isPa(i - 1, j - 1)) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
            }
        }

        cout << dp[n] << '\n';
    }
}