#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int way[2][2] = {{1, 0}, {0, 1}};

int n;
bool vis[MAXN][MAXN];
string board[MAXN];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 2; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (tx < n && ty < n && board[tx][ty] != '.' && !vis[tx][ty]) {
            dfs(tx, ty);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'x' && !vis[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << "Case " << kase << ": " << ans << '\n';
    }
}