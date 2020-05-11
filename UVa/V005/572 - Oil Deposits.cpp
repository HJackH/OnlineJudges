#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int way[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int m, n;
bool vis[MAXN][MAXN];
string matrix[MAXN];


void dfs(int k, int l) {
    vis[k][l] = true;
    for (int i = 0; i < 8; i++) {
        int x = k + way[i][0];
        int y = l + way[i][1];
        if ((x >= 0 && x < m && y >= 0 && y < n) && !vis[x][y] && matrix[x][y] == '@') {
            dfs(x, y);
        }
    }
}

int main() {
    while (cin >> m >> n && m) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++) {
            cin >> matrix[i];
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && matrix[i][j] == '@') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}