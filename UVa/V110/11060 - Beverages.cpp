#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100 + 5;

int n, m, in[MAXN];
string s1, s2, sa[MAXN];
unordered_map<string, int> mp;
vector<int> G[MAXN], ans;

void solve() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        ans.push_back(now);
        --in[now];

        for (int to : G[now]) {
            --in[to];
        }

        for (int i = 0; i < n; i++) {
            if (!in[i]) {
                q.push(i);
                break;
            }
        }
    }
}

int main() {
    IOS
    int kase = 0;
    while (cin >> n) {
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> sa[i];
            mp[sa[i]] = i;
            G[i].clear();
            in[i] = 0;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            G[mp[s1]].push_back(mp[s2]);
            ++in[mp[s2]];
        }

        ans.clear();
        solve();

        cout << "Case #" << ++kase << ": Dilbert should drink beverages in this order:";
        for (int i : ans) {
            cout << ' ' << sa[i];
        }
        cout << ".\n\n";
    }
}