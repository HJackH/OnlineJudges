#include <bits/stdc++.h>
using namespace std;

int height, up, down, fac;

int main() {
    while (cin >> height >> up >> down >> fac && height) {
        height *= 100;
        up *= 100;
        down *= 100;
        fac = fac * up / 100;

        int day = 0, len = 0;
        while (0 <= len && len <= height) {
            len += max(up - fac * day, 0);
            day++;
            if (len > height) {
                break;
            }
            len -= down;
        }

        if (len > height) {
            cout << "success on day " << day << '\n';
        } else {
            cout << "failure on day " << day << '\n';
        }
    }
}
