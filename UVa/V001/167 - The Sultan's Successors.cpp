#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8;

int ans, place[MAXN + 5], board[MAXN + 5][MAXN + 5];
bool vis[3][2 * MAXN + 5];

void dfs(int n) {
    if (n == 9) {
        int sum = 0;
        for (int i = 1; i <= MAXN; i++) {
            sum += board[place[i]][i];
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i <= MAXN; i++) {
        if (!vis[0][i] && !vis[1][n + i] && !vis[2][n - i + MAXN]) {
            vis[0][i] = vis[1][n + i] = vis[2][n - i + MAXN] = true;
            place[n] = i;
            dfs(n + 1);
            vis[0][i] = vis[1][n + i] = vis[2][n - i + MAXN] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 1; i <= MAXN; i++) {
            for (int j = 1; j <= MAXN; j++) {
                cin >> board[i][j];
            }
        }

        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        printf("%5d\n", ans);
    }   
}