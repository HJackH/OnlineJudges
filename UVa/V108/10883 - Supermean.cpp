#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        int n;
        cin >> n;

        double ans = 0, a, c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            double sum = log2(abs(a));

            if (i) {
                c += log2(double(n - i) / i);
                sum += c;
            }

            if (a < 0) {
                ans -= pow(2, sum - (n - 1));
            } else {
                ans += pow(2, sum - (n - 1));
            }
        }

        printf("Case #%d: %.3lf\n", kase, ans);
    }
}