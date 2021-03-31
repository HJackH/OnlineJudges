#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const double EPS = 1e-3;
const int MAXN = 8 + 5;

struct Air {
    int st;
    int ed;
};

int n, ord[MAXN];
Air airs[MAXN];

bool judge(double limit) {
    double now = -1;
    for (int i = 0; i < n; i++) {
        if ((airs[ord[i]].st - now) > EPS) {
            now = airs[ord[i]].st + limit;
        } else if ((now - airs[ord[i]].ed) > EPS) {
            return false;
        } else {
            now = now + limit;
        }
    }
    return true;
}

int main() { IOS
    int kase = 0;
    while (cin >> n && n) {
        Air t;
        for (int i = 0; i < n; i++) {
            cin >> t.st >> t.ed;
            t.st *= 60;
            t.ed *= 60;
            airs[i] = t;
            ord[i] = i;
        }

        double ans = 0;
        do {
            double L = 0, R = 86400;
            while (abs(L - R) > EPS) {
                double M = (L + R) / 2.0;
                if (judge(M)) {
                    L = M;
                } else {
                    R = M;
                }
            }
            ans = max(ans, L);
        } while (next_permutation(ord, ord + n));

        printf("Case %d: %d:%02d\n", ++kase, int(round(ans)) / 60, int(round(ans)) % 60);
    }
}