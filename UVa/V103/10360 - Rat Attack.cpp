#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXX = 1024;

int n, d, board[MAXX + 5][MAXX + 5];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> d >> n;
        memset(board, 0, sizeof(board));

        int rx, ry, rsize;
        for (int i = 0; i < n; i++) {
            cin >> rx >> ry >> rsize;

            int stx = max(0, rx - d);
            int edx = min(MAXX, rx + d);
            int sty = max(0, ry - d);
            int edy = min(MAXX, ry + d);
            for (int x = stx; x <= edx; x++) {
                for (int y = sty; y <= edy; y++) {
                    board[x][y] += rsize;
                }
            }
        }

        int ansx, ansy, ans = 0;
        for (int x = MAXX; x >= 0; x--) {
            for (int y = MAXX; y >= 0; y--) {
                if (board[x][y] >= ans) {
                    ans = board[x][y];
                    ansx = x;
                    ansy = y;
                }
            }
        }

        cout << ansx << ' ' << ansy << ' ' << ans << '\n';
    }
}