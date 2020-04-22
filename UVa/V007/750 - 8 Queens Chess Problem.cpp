#include <bits/stdc++.h>
using namespace std;

int T, x, y, vis[3][20], place[20], cnt;

void dfs(int n) {
    if (n == 9) {
        printf("%2d      ", ++cnt);
        for (int i = 1; i <= 8; i++) {
            cout << place[i];
            if (i == 8) {
                cout << '\n';
            } else {
                cout << ' ';
            }
        }
        return;
    }
    if (n == y) {
        dfs(n + 1);
    } else {
        //row
        for (int i = 1; i <= 8; i++) {
            if (!vis[0][i] && !vis[1][n + i] && !vis[2][n - i + 8]) {
                vis[0][i] = vis[1][n + i] = vis[2][n - i + 8] = 1;
                place[n] = i;
                dfs(n + 1);
                vis[0][i] = vis[1][n + i] = vis[2][n - i + 8] = 0;
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        cin >> x >> y;
        place[y] = x;
        vis[0][x] = vis[1][x + y] = vis[2][y - x + 8] = 1;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        dfs(1);
        if (T) {
            cout << '\n';
        }
    }
}