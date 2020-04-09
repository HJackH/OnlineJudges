#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 50;
const double EPS = 1e-8;

struct Point {
    double x;
    double y;
    bool operator < (const Point &other) const {
        if (fabs(x - other.x) < EPS) {
            return (y - other.y < EPS);
        } else {
            return (x - other.x < EPS);
        }
    }
};

int n;
Point points[MAXN];

double dis(int pa, int pb) {
    double tx = points[pa].x - points[pb].x;
    double ty = points[pa].y - points[pb].y;
    return sqrt(tx * tx + ty * ty);
}

double closest(int l, int r) {
    if (l == r) {
        return 11000.0;
    }
    int mid = l + (r - l) / 2;
    double d = min(closest(l, mid), closest(mid + 1, r)), ansd = d;
    double midX = (points[mid + 1].x + points[mid].x) / 2;
    for (int i = mid; i >= l; i--) {
        if (points[i].x - midX + d < EPS) {
            break;
        }
        for (int j = mid + 1; j <= r; j++) {
            if (points[j].x - midX - d > EPS) {
                break;
            }
            ansd = min(ansd, dis(i, j)); 
        }
    }
    return ansd;
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        sort(points, points + n);

        double ans = closest(0, n - 1);
        if (fabs(ans - 10000.0) < EPS || ans > 10000.0) {
            printf("INFINITY\n"); 
        } else {
            printf("%.4lf\n", ans);
        }
    }
}