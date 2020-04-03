//Brute Force
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 50;
const double EPS = 1e-8;

struct Board {
    double d;
    double l;
    double r;
    bool operator < (const Board &other) const {
        return d < other.d;
    }
};

int T, n;
double w;
Board boards[MAXN];

double calcM(double xU, double yU, double xD, double yD) {
    if (fabs(yU - yD) < EPS) {
        return xD;
    }
    return (-yD * (xD - xU) / (yD - yU) + xD);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> w >> n;
        for (int i = 0; i < n; i++) {
            cin >> boards[i].d >> boards[i].l >> boards[i].r;
        }
        sort(boards, boards + n);

        bool chk = true;
        double L = 0, R = w;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                L = max(L, calcM(boards[i].r, boards[i].d, boards[j].l, boards[j].d));
                R = min(R, calcM(boards[i].l, boards[i].d, boards[j].r, boards[j].d));
            }
            
            if (L - R > EPS) {
                chk = false;
                break;
            }
        }

        if (chk) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
