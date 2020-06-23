#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;
const int INF = 1e9;

int n, w[MAXN][MAXN];
int lx[MAXN], ly[MAXN], my[MAXN];
bool vx[MAXN], vy[MAXN];

bool match(int i) {
    vx[i] = true;
    for (int j = 1; j <= n; j++) {
        if (lx[i] + ly[j] == w[i][j] && !vy[j]) {
            vy[j] = true;
            if (!my[j] || match(my[j])) {
                my[j] = i;
                return true;
            }
        }
    }
    return false;
}

void update() {
    int delta = INF;

    for (int i = 1; i <= n; i++) {
        if (vx[i]) {
            for (int j = 1; j <= n; j++) {
                if (!vy[j]) {
                    delta = min(delta, lx[i] + ly[j] - w[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vx[i]) {
            lx[i] -= delta;
        }
        if (vy[i]) {
            ly[i] += delta;
        }
    }
}

void KM() {
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(my, 0, sizeof(my));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], w[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        while (true) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));

            if (match(i)) {
                break;
            } else {
                update();
            }
        }
    }
}

int main() {
    int T = 15;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> w[i][j];
            }
        }

        KM();

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cout << lx[i];
            ans += lx[i];
            if (i != n) {
                cout << ' ';
            } else {
                cout << '\n';
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ly[i];
            ans += ly[i];
            if (i != n) {
                cout << ' ';
            } else {
                cout << '\n';
            }
        }
        cout << ans << '\n';
    }
}