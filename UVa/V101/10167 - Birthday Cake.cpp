#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

struct Pos{
    int x;
    int y;
};

int n;
Pos pos[MAXN];

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < 2 * n; i++) {
            cin >> pos[i].x >> pos[i].y;
        }

        bool flag = true;
        for (int a = -500; a <= 500 && flag; a++) {
            for (int b = -500; b <= 500 && flag; b++) {
                int sl = 0, sr = 0;
                for (int i = 0; i < 2 * n; i++) {
                    if (a * pos[i].x + b * pos[i].y > 0) {
                        sl++;
                    }
                    if (a * pos[i].x + b * pos[i].y < 0) {
                        sr++;
                    }
                }
                if (sl == n && sr == n) {
                    cout << a << " " << b << '\n';
                    flag = false;
                }
            }
        }
    }
}