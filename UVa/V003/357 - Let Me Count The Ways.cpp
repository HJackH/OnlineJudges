#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
const int coin[] = {0, 1, 5, 10, 25, 50};

int n;
long long dp[MAXN + 5][5 + 5];

int main() {
    for (int i = 0; i <= MAXN; i++) {
        dp[i][1] = 1;
    }
    for (int j = 2; j <= 5; j++) {
        for (int i = 0; i <= MAXN; i++) {
            if (i < coin[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - coin[j]][j];
            }
        }
    }

    while (cin >> n) {
        if (dp[n][5] <= 1) {
            cout << "There is only " << dp[n][5] << " way";
        } else {
            cout << "There are " << dp[n][5] << " ways";
        }
        cout << " to produce " << n << " cents change.\n";
    }
}