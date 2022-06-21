#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 1000 + 5;
const int way[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

struct Pos {
    int x;
    int y;
    int w;
};

int n, m;
string board[MAXN];
int vis[MAXN][MAXN];

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool edge(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

void bfs_fire(int stx, int sty) {
    vis[stx][sty] = 0;
    queue<Pos> q;
    q.push({stx, sty, 0});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now.w > vis[now.x][now.y]) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (!in(tx, ty)) {
                continue;
            }
            if (board[tx][ty] == '#') {
                continue;
            }
            if (vis[tx][ty] > now.w + 1) {
                vis[tx][ty] = now.w + 1;
                q.push({tx, ty, vis[tx][ty]});
            }
        }
    }
}

int bfs_joe(int stx, int sty) {
    vis[stx][sty] = 0;
    queue<Pos> q;
    q.push({stx, sty, 0});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (edge(now.x, now.y)) {
            return now.w;
        }
        if (now.w > vis[now.x][now.y]) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (!in(tx, ty)) {
                continue;
            }
            if (board[tx][ty] == '#') {
                continue;
            }
            if (vis[tx][ty] > now.w + 1) {
                vis[tx][ty] = now.w + 1;
                q.push({tx, ty, vis[tx][ty]});
            }
        }
    }
    return -1;
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            vis[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                bfs_fire(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'J') {
                int ans = bfs_joe(i, j);
                if (ans == -1) {
                    cout << "IMPOSSIBLE\n";
                } else {
                    cout << ans + 1 << "\n";
                }
                return;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
}