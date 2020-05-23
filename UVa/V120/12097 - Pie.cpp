#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 5;
const double EPS = 1e-4;

int T, n, f;
double a[MAXN];

bool ok(double area) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += M_PI * a[i] * a[i] / area;
    }
    return cnt >= f;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> f;
        f++;

        double L = 0, R = 0, mid;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            R += M_PI * a[i] * a[i];
        }

        R /= f;
        while (R - L > EPS) {
            mid = (L + R) / 2; 
            if (ok(mid)) {
                L = mid;
            } else {
                R = mid;
            }
        }

        printf("%.4lf\n", L);
    }
}