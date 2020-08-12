#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 26;

int ind[MAXN + 5], dtime[MAXN + 5], ans;
string input;
vector<int> G[MAXN + 5];

void dfs(int x, int cost) {
    ans = max(ans, cost);
    for (int i : G[x]) {
        dfs(i, cost + dtime[i]);
    }
}

int main() {
    IOS
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--) {
        for (int i = 0; i < MAXN; i++) {
            ind[i] = 0;
            dtime[i] = 0;
            G[i].clear();
        }
        while (getline(cin, input) && input.length() > 0) {
            stringstream ss(input);
            char to;
            int day;
            string from;
            ss >> to >> day >> from;
            dtime[to - 'A'] = day;
            for (char c : from) {
                G[c - 'A'].push_back(to - 'A');
                ind[to - 'A']++;
            }
        }
        ans = 0;
        for (int i = 0; i < MAXN; i++) {
            if (!ind[i]) {
                dfs(i, dtime[i]);
            }
        }
        cout << ans << '\n';
        if (T) {
            cout << '\n';
        }
    }
}