#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 50000 + 5;
const int MAXL = MAXN * 200 + 5;
const int MAXC = 2 + 5;

struct Trie {
    int nex[MAXL][MAXC];
    int cnt[MAXL];
    int sz;
    void init() {
        memset(nex, 0, sizeof(nex));
        memset(cnt, 0, sizeof(cnt));
        sz = 0;
    }
    LL insert(const string &str) {
        int p = 0;
        LL ret = 0;
        for (int i = 0; i < str.size(); i++) {
            int id = str[i] - '0';
            if (!nex[p][id]) {
                nex[p][id] = ++sz;
            }
            p = nex[p][id];
            cnt[p]++;
            ret = max(ret, 1LL * (i + 1) * cnt[p]);
        }
        return ret;
    }
};

Trie tr;

int main() {
    int T;
    cin >> T;
    while (T--) {
        tr.init();
        int n;
        string s;
        LL ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            ans = max(ans, tr.insert(s));
        }
        cout << ans << "\n";
    }
}