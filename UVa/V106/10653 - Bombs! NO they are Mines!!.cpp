#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
const int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Pos {
    int x;
    int y;
    int depth;
};

int r, c;
bool vis[MAXN][MAXN];
Pos st, ed;

int bfs() {
    queue<Pos> q;
    vis[st.x][st.y] = true;
    q.push({st.x, st.y, 0});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now.x == ed.x && now.y == ed.y) {
            return now.depth;
        }
        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c && !vis[tx][ty]) {
                vis[tx][ty] = true;
                q.push({tx, ty, now.depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    while (cin >> r >> c && (r || c)) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                vis[i][j] = false;
            }
        }

        int n, m, rt, ct;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> rt >> m;
            for (int j = 0; j < m; j++) {
                cin >> ct;
                vis[rt][ct] = true;
            }
        }

        cin >> st.x >> st.y >> ed.x >> ed.y;
        cout << bfs() << '\n';
    }
}