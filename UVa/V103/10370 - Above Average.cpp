#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

int n, a[MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        double avg = 0.0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            avg += a[i];
        }
        avg /= n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > avg) {
                cnt++;
            }
        }
        printf("%.3lf%%\n", (double)cnt / n * 100.0);
    }
}