#include <bits/stdc++.h>
using namespace std;

double t1, t2, s1, s2, w, width, height;

double getArea(double tw) {
    double ly = t1 + tw, ry = t2 + tw;
    double tx = s2 - tw, bx = s1 - tw;

    bool on_left = s1 <= ly && ly <= s2;
    bool on_right = s1 <= ry && ry <= s2;
    bool on_top = t1 <= tx && tx <= t2;
    bool on_bottom = t1 <= bx && bx <= t2;

    if (on_left && on_right) {
        return (s2 - ly + s2 - ry) * width / 2;
    }
    if (on_left && on_top) {
        return (s2 - ly) * (tx - t1) / 2;
    }
    if (on_bottom && on_right) {
        return height * width - (t2 - bx) * (ry - s1) / 2;
    }
    if (on_bottom && on_top) {
        return (tx - t1 + bx - t1) * height / 2;
    }
    return ly <= s1 ? height * width : 0;
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> t1 >> t2 >> s1 >> s2 >> w;
        width = t2 - t1;
        height = s2 - s1;

        double a1 = getArea(w);
        double a2 = getArea(-w);
        printf("Case #%d: %.6lf\n", kase, (a2 - a1) / width / height);
    }
}