#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
const int MAXN = 200 + 5;

struct Pos {
    double x;
    double y;
};

Pos operator + (const Pos &a, const Pos &b) {
    return {a.x + b.x, a.y + b.y};
}

Pos operator - (const Pos &a, const Pos &b) {
    return {a.x - b.x, a.y - b.y};
}

Pos operator / (const Pos &a, double c) {
    return {a.x / c, a.y / c};
}

Pos operator * (const Pos &a, double c) {
    return {a.x * c, a.y * c};
}

// ostream& operator << (ostream &o, const Pos &a) {
//     o << "(" << a.x << ", " << a.y << ")";
//     return o;
// }

int n;
Pos p[MAXN];

double dis(const Pos &a, const Pos &b) {
    auto d = a - b;
    return sqrt(d.x * d.x + d.y * d.y);
}

int cal(Pos m) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dis(m, p[i]) - 2.5 <= EPS) {
            cnt++;
        }
    }
    return cnt;
}

int chk(int a, int b) {
    auto p1 = p[a];
    auto p2 = p[b];

    Pos mid = (p1 + p2) / 2.0;

    double d = dis(p1, p2);
    
    // normal vector
    Pos u = {p1.y - p2.y, p2.x - p1.x};

    double du = dis({0, 0}, u);
    u = u / du;

    double len = sqrt(2.5 * 2.5 - 0.25 * d * d + EPS);
    u = u * len;

    Pos m1 = mid + u;
    Pos m2 = mid - u;

    return max(cal(m1), cal(m2));
}

int main() {
    int T;
    cin >> T;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (T--) {
        n = 0;
        stringstream ss;
        while (getline(cin, s) && s.size() > 0) {
            ss.str("");
            ss.clear();
            ss << s;
            ss >> p[n].x >> p[n].y;
            n++;
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // assert(dis(p[i], p[j]) > EPS);
                if (dis(p[i], p[j]) - 5.0 <= EPS) {
                    ans = max(ans, chk(i, j));
                }
            }
        }

        cout << ans << "\n";
        if (T) {
            cout << "\n";
        }
    }
}