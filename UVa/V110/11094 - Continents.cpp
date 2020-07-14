#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 5;
const int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int m, n, x, y;
bool vis[MAXN][MAXN];
string board[MAXN];

bool check(int &k, int &l) {
    l = (l + n) % n;
    return k >= 0 && k < m && board[k][l] == board[x][y] && !vis[k][l];
}

void dfs(int k, int l, int &cnt) {
    cnt++;
    vis[k][l] = true;
    for (int i = 0; i < 4; i++) {
        int tk = k + way[i][0];
        int tl = l + way[i][1];
        if (check(tk, tl)) {
            vis[tk][tl] = true;
            dfs(tk, tl, cnt);
        }
    }
}

int main() {
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            cin >> board[i];
        }
        cin >> x >> y;

        memset(vis, 0, sizeof(vis));
        int tmp = 0, ans = 0;
        dfs(x, y, tmp);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == board[x][y] && !vis[i][j]) {
                    tmp = 0;
                    dfs(i, j, tmp);
                    ans = max(ans, tmp);
                }
            }
        }
        cout << ans << '\n';
    }
}