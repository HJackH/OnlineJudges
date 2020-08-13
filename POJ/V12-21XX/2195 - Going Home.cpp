#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int INF = 1e9;
const int MAXN = 100 + 5;

struct Pos {
    int x;
    int y;
};

struct KM { //1-base
    int n, G[MAXN][MAXN];
    int lx[MAXN], ly[MAXN], my[MAXN];
    bool vx[MAXN], vy[MAXN];
    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = 0;
            }
        }
    }
    bool match(int i) {
        vx[i] = true;
        for (int j = 1; j <= n; j++) {
            if (lx[i] + ly[j] == G[i][j] && !vy[j]) {
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
                        delta = min(delta, lx[i] + ly[j] - G[i][j]);
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
    int run() {
        for (int i = 1; i <= n; i++) {
            lx[i] = ly[i] = my[i] = 0;
            for (int j = 1; j <= n; j++) {
                lx[i] = max(lx[i], G[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            while (true) {
                for (int i = 1; i <= n; i++) {
                    vx[i] = vy[i] = 0;
                }
                if (match(i)) {
                    break;
                } else {
                    update();
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += lx[i] + ly[i];
        }
        return ans;
    }
};

int bn, bm;
string board[MAXN];
vector<Pos> house, men;
KM km1;

int main() {
    while (cin >> bn >> bm && (bn || bm)) {
        house.clear();
        men.clear();

        for (int i = 0; i < bn; i++) {
            cin >> board[i];
            for (int j = 0; j < bm; j++) {
                if (board[i][j] == 'H') {
                    house.push_back({i, j});
                } else if (board[i][j] == 'm') {
                    men.push_back({i, j});
                }
            }
        }

        km1.init(house.size());

        for (int i = 1; i <= km1.n; i++) {
            for (int j = 1; j <= km1.n; j++) {
                km1.G[i][j] = -(abs(house[i- 1].x - men[j - 1].x) + abs(house[i- 1].y - men[j - 1].y));
            }
        }

        cout << -km1.run() << '\n';
    }
}