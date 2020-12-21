#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 25 + 5;
const int way[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

int n;
string board[MAXN];
bool vis[MAXN][MAXN];

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y) {
    if (!in(x, y) || board[x][y] == '0' || vis[x][y]) {
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        dfs(x + way[i][0], y + way[i][1]);
    }
}

int main() { IOS
    int kase = 0;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1' && !vis[i][j]) {
                    ++ans;
                    dfs(i, j);
                }
            }
        }

        cout << "Image number " << ++kase << " contains " << ans << " war eagles.\n";
    }
}