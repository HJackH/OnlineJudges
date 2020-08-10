#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
const int MAXN = 30000;

double n;
int dollar[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[MAXN + 5];

int main() {
    dp[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = dollar[i]; j <= MAXN; j++) {
            dp[j] += dp[j - dollar[i]];
        }
    }
    while (cin >> n && n > EPS) {
        printf("%6.2lf", n);
        int tn = round(n * 100) + 0.4;
        printf("%17lld\n", dp[tn]);
    }
}