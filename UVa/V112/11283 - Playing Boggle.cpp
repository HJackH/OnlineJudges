#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int way[8][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};
const int reward[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

string board[4], s;
bool vis[4][4];

bool in(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bool dfs(int x, int y, int j) {
    vis[x][y] = 1;
    if (board[x][y] == s[j]) {
        if (j == s.length() - 1) {
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int tx = x + way[i][0];
            int ty = y + way[i][1];
            if (in(tx, ty) && !vis[tx][ty] && dfs(tx, ty, j + 1)) {
                return true;
            }
        }
    }
    vis[x][y] = 0;
    return false;
}

int solve() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (dfs(i, j, 0)) {
                return reward[min((int)s.length(), 8)];
            }
        }
    }
    return 0;
}

int main() { IOS
    int T, kase = 0;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++) {
            cin >> board[i];
        }

        int m, ans = 0;
        cin >> m;
        while (m--) {
            cin >> s;
            ans += solve();
        }
        cout << "Score for Boggle game #" << ++kase << ": " << ans << '\n';
    }
}