#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXP = 100 + 5;
const int MAXN = 300 + 5;

int p, n, pre[MAXN];
bitset<MAXN> vis;
vector<int> G[MAXP];

bool match(int i) {
    for (auto j : G[i]) {
        if (!vis[j]) {
            vis[j] = 1;
            if (!pre[j] || match(pre[j])) {
                pre[j] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> p >> n;
        int cnt, stu;
        for (int i = 1; i <= p; i++) {
            G[i].clear();
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                cin >> stu;
                G[i].push_back(stu);
            }
        }

        memset(pre, 0, sizeof(pre));
        int ans = 0;
        for (int i = 1; i <= p; i++) {
            vis.reset();
            if (match(i)) {
                ans++;
            }
        }
        if (ans == p) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}