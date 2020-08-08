#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100 + 5;
const int MAXP = 500 + 5;

int n, a[MAXN], dp[MAXN * MAXP];

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }  
        int half = sum / 2;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = half; j >= a[i]; j--) {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        cout << sum - 2 * dp[half] << '\n';
    }
}