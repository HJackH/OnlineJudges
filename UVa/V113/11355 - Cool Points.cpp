#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 500;

struct Item {
    double angle;
    int diff;
    bool operator < (const Item &other) const {
        return angle < other.angle;
    }
};

int n, r, k;
Item a[MAXN];

void add(double x, double y) {
    a[k++] = {x, 1};
    a[k++] = {y, -1};
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> r;
        k = 0;
        double x1, y1, x2, y2;
        for (int i = 0; i < n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            double a1 = atan2(y1, x1);
            double a2 = atan2(y2, x2);
            if (a1 < a2) {
                swap(a1, a2);
            }
            if (a1 - a2 > PI) {
                add(a1, PI);
                add(-PI, a2);
            } else {
                add(a2, a1);
            }
        }

        sort(a, a + k);
        int cnt = 0;
        double ans = 0, last = -PI;
        for (int i = 0; i < k; i++) {
            if (!cnt) {
                ans += a[i].angle - last;
            }
            cnt += a[i].diff;
            last = a[i].angle;
        }
        ans += PI - last;
        printf("Case %d: %.2lf%%\n", kase, 100.0 * ans / (2 * PI));
    }
}