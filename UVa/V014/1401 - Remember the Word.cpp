#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MOD = 20071027;
const int MAXS = 300000 + 5;
const int MAXL = 4000 * 100 + 5;
const int MAXC = 26 + 5;

struct Trie {
    int nex[MAXL][MAXC];
    int len[MAXL];
    int sz;
    void init() {
        memset(nex, 0, sizeof(nex));
        memset(len, 0, sizeof(len));
        sz = 0;
    }
    void insert(const string &str) {
        int p = 0;
        for (char c : str) {
            int id = c - 'a';
            if (!nex[p][id]) {
                nex[p][id] = ++sz;
            }
            p = nex[p][id];
        }
        len[p] = str.length();
    }
    vector<int> find(const string &str, int i) {
        int p = 0;
        vector<int> ans;
        for (; i < str.length(); i++) {
            int id = str[i] - 'a';
            if (!nex[p][id]) {
                return ans;
            }
            p = nex[p][id];
            if (len[p]) {
                ans.pb(len[p]);
            }
        }
        return ans;
    }
};

string s;
int dp[MAXS];
Trie tr;

int main() { IOS
    int kase = 0;
    while (cin >> s) {
        int n = s.length(), m;
        tr.init();
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;

        string tmp;
        cin >> m;
        while (m--) {
            cin >> tmp;
            tr.insert(tmp);
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<int> vc = tr.find(s, i);
            for (int j : vc) {
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }

        cout << "Case " << ++kase << ": " << dp[0] << "\n";
    }
}