#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;
const int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, cnt;
bool vis[MAXN][MAXN];
string board[MAXN];

bool inb(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs_X(int x, int y) {
    // fill 'X' with '*'
    board[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (inb(tx, ty) && board[tx][ty] == 'X') {
            dfs_X(tx, ty);
        }
    }
}

void dfs_die(int x, int y) {
    if (board[x][y] == 'X') {
        ++cnt;
        dfs_X(x, y);
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (inb(tx, ty) && board[tx][ty] != '.' && !vis[tx][ty]) {
            dfs_die(tx, ty);
        }
    }
}

int main() {
    int kase = 0;
    while (cin >> m >> n && (n || m)) {
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }
        memset(vis, 0, sizeof(vis));
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.' && !vis[i][j]) {
                    cnt = 0;
                    dfs_die(i, j);
                    ans.push_back(cnt);
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Throw " << ++kase << '\n';
        for (int i = 0, ed = ans.size(), first = true; i < ed; i++) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << ans[i];
        }
        cout << "\n\n";
    }
}