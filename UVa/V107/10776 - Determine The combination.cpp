#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
const int MAXN = 30 + 5;

int r;
string s, choose;
unordered_set<string> vis;
vector<string> ans;

void dfs(int i, int lv) {
    if (vis.count(choose)) {
        return;
    }
    vis.insert(choose);
    if (lv == r) {
        ans.eb(choose);
        return;
    }
    for (int j = i; j < s.size(); j++) {
        choose += s[j];
        dfs(j + 1, lv + 1);
        choose.pop_back();
    }
}

int main() { IOS
    choose.reserve(MAXN);
    while (cin >> s >> r) {
        sort(s.begin(), s.end());
        ans.clear();
        vis.clear();
        dfs(0, 0);
        for (auto i : ans) {
            cout << i << "\n";
        }
    }
}