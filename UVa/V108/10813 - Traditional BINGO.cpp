#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 5;
const int MAXB = 75;

struct Pos {
    int x;
    int y;
};

int a[MAXN + 5][MAXN + 5], col[MAXN + 5], row[MAXN + 5], dia[2 + 5];
unordered_map<int, Pos> M;

bool chk(int num) {
    if (M.count(num)) {
        auto at = M[num];
        int cnt = 0;
        cnt = max(cnt, ++row[at.x]);
        cnt = max(cnt, ++col[at.y]);
        if (at.x == at.y) {
            cnt = max(cnt, ++dia[0]);
        }
        if (at.x + at.y == MAXN - 1) {
            cnt = max(cnt, ++dia[1]);
        }
        if (cnt >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        M.clear();
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        col[2] = row[2] = dia[0] = dia[1] = 1;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                if (i == 2 && j == 2) {
                    continue;
                }
                cin >> a[i][j];
                M[a[i][j]] = {i, j};
            }
        }
        int ans = 0, num;
        for (int i = 1; i <= MAXB; i++) {
            cin >> num;
            if (!ans && chk(num)) {
                ans = i;
            }
        }
        cout << "BINGO after " << ans << " numbers announced\n";
    }
}