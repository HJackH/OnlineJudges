#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int INF = 1e9;
const int MAXN = 1e6 + 5;

int R, L, n;
int num[MAXN], zero[MAXN], tmp[MAXN], can[MAXN], cost[MAXN];

void sol() {
    int zn = 0, now = 0;
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            zero[zn++] = i;
            can[now++]++;
        } else {
            now += num[i];
            int k = min(zn, num[i]);
            for (int j = 1; j <= k; j++) {
                int at = now - j;
                tmp[at] = i - zero[zn - j] - j + 1;
                cost[at] += tmp[at];
                can[at]++;
            }
        }
    }

    reverse(num, num + n);

    zn = 0, now--;
    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            zero[zn++] = i;
            now--;
        } else {
            now -= num[i];
            int k = min(zn, num[i]);
            for (int j = 1; j <= k; j++) {
                int at = now + j;
                if (tmp[at] == -1) {
                    tmp[at] = i - zero[zn - j] - j + 1;
                    cost[at] += tmp[at];
                    can[at]++;
                } else {
                    cost[at] += min(0, i - zero[zn - j] - j + 1 - tmp[at]);
                }
            }
        }
    }
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> R >> L;
        memset(can, 0, sizeof(can));
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i < R; i++) {
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> num[j];
            }
            sol();
        }

        int mn = INF;
        for (int i = 0; i < L; i++) {
            if (can[i] == R) {
                mn = min(mn, cost[i]);
            }
        }
        cout << mn << "\n";

        for (int i = 0; i < L; i++) {
            if (can[i] == R && cost[i] == mn) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}