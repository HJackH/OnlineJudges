#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100 + 5;
const int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, board[MAXN][MAXN], route[MAXN][MAXN];
string name;

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int len) {
    route[x][y] = len;
    for (int i = 0; i < 4; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (in(tx, ty) && board[x][y] > board[tx][ty] && route[tx][ty] < len + 1) {
            dfs(tx, ty, len + 1);
        }
    }
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> name >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
                route[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!route[i][j]) {
                    dfs(i, j, 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, route[i][j]);
            }
        }
        cout << name << ": " << ans << '\n';
    }
}