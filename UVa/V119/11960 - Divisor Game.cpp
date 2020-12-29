#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define F first
#define S second
const int MAXN = 1e6;

vector<pair<int, int>> ans(MAXN + 5);

void table() {
    vector<int> cnt(MAXN + 5, 0);
    for (int i = 1; i <= MAXN; i++) {
        int sqi = sqrt(i);
        for (int j = 1; j <= sqi; j++) {
            if (i % j == 0) {
                if (i / j == j) {
                    ++cnt[i];
                } else {
                    cnt[i] += 2;
                }
            }
        }
        
        if (ans[i - 1].S <= cnt[i]) {
            ans[i] = mp(i, cnt[i]);
        } else {
            ans[i] = ans[i - 1];
        }
    }
}

int main() { IOS
    table();

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << ans[n].F << '\n';
    }
}