#include <bits/stdc++.h>
using namespace std;
const int MAXN = 81 + 5;

int n;
int a[MAXN][4], vis[10];

int choose(int idx) {
    int flag = 1;
    for (int i = 0; i < 3; i++) {
        if (vis[a[idx][i]]) {
            flag = 0;
        }
        vis[a[idx][i]]++;
    }
    return flag;
}

void recover(int idx) {
    for (int i = 0; i < 3; i++) {
        vis[a[idx][i]]--;
    }
}

int main() {
    int kase = 0;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> a[i][j];
            }
        }

        int ans = -1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (!choose(i)) {
                recover(i);
                continue;
            }
            sum += a[i][3];
            for (int j = i + 1; j < n; j++) {
                if (!choose(j)) {
                    recover(j);
                    continue;
                }
                sum += a[j][3];
                for (int k = j + 1; k < n; k++) {
                    if (!choose(k)) {
                        recover(k);
                        continue;
                    }
                    sum += a[k][3];
                    ans = max(ans, sum);
                    sum -= a[k][3];
                    recover(k);
                }
                sum -= a[j][3];
                recover(j);
            }
            sum -= a[i][3];
            recover(i);
        }

        cout << "Case " << ++kase << ": " << ans << "\n";
    }
}