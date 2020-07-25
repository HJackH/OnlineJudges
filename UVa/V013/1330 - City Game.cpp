#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

int n, m;
char board[MAXN][MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> board[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] == 'R') {
                    continue;
                }
                int limit = n;
                for (int k = i; k <= m; k++) {
                    for (int l = j; l <= limit; l++) {
                        if (board[k][l] == 'R') {
                            limit = l - 1;
                            break;
                        }
                        ans = max(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
        cout << ans * 3 << '\n';
    }
}