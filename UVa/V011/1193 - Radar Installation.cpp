#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;

struct Pos {
    int x;
    int y;
    double ls;
    double rs;
    bool operator < (Pos const &other) const {
        if (rs != other.rs) {
            return rs < other.rs;
        } else {
            return ls < other.ls;
        }
    }
};

int n, d, kase = 0;
Pos pos[MAXN];

int main() {
    while (cin >> n >> d && n && d) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            cin >> pos[i].x >> pos[i].y;
            if (flag) {
                if (d >= abs(pos[i].y)) {
                    double dis = sqrt(d * d - pos[i].y * pos[i].y);
                    pos[i].ls = pos[i].x - dis;
                    pos[i].rs = pos[i].x + dis;
                } else {
                    flag = false;
                }
            }
        }

        cout << "Case " << ++kase << ": ";
        if (!flag) {
            cout << "-1\n";
            continue;
        }

        sort(pos, pos + n);
        
        int ans = 0;
        double now = -1e10;
        for (int i = 0; i < n; i++) {
            if (pos[i].ls > now) {
                now = pos[i].rs;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}