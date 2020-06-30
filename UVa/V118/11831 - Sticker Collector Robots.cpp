#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Pos {
    int x;
    int y;
    int face;
};

int n, m, s;
bool vis[MAXN][MAXN];
string cmd, arena[MAXN];

bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && arena[x][y] != '#');
}

int main() {
    while (cin >> n >> m >> s && (n || m || s)) {
        Pos now;
        bool found = false;
        for (int i = 0; i < n; i++) {
            cin >> arena[i];
            if (!found) {
                for (int j = 0; j < m; j++) {
                    switch (arena[i][j])
                    {
                    case 'N':
                        now = {i, j, 0};
                        found = true;
                        break;

                    case 'L':
                        now = {i, j, 1};
                        found = true;
                        break;

                    case 'S':
                        now = {i, j, 2};
                        found = true;
                        break;

                    case 'O':
                        now = {i, j, 3};
                        found = true;
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        cin >> cmd;

        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < s; i++) {
            if (cmd[i] == 'F') {
                int tx = now.x + way[now.face][0];
                int ty = now.y + way[now.face][1];
                if (check(tx, ty)) {
                    now = {tx, ty, now.face};
                    if (arena[tx][ty] == '*' && !vis[tx][ty]) {
                        ans++;
                        vis[tx][ty] = true;
                    }
                }
            } else if (cmd[i] == 'D') {
                now.face = (now.face + 1) % 4;
            } else {
                now.face = (now.face - 1 + 4) % 4;
            }
        }

        cout << ans << '\n';
    }
}