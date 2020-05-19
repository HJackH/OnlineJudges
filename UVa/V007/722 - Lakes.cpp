#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int T, row, col, ans;
string board[MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y) {
    vis[x][y] = true;
    ans++;
    for (int i = 0; i < 4; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (tx >= 0 && tx < row && ty >= 0 && ty < col && 
                board[tx][ty] != '1' && !vis[tx][ty]) {
            dfs(tx, ty);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cin.ignore(1);

        row = 0;
        while (getline(cin, board[row]) && board[row].length()) {
            row++;
        }
        col = board[0].length();

        memset(vis, 0, sizeof(vis));
        ans = 0;
        dfs(n - 1, m - 1);

        cout << ans << '\n';
        if (T) {
            cout << '\n';
        }
    }
}