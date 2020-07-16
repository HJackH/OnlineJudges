#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int n, m;
vector<int> pos[MAXN + 5];

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= MAXN; i++) {
            pos[i].clear();
        }
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            pos[tmp].push_back(i);
        }
        
        int k, v;
        for (int i = 0; i < m; i++) {
            cin >> k >> v;
            if (k > pos[v].size()) {
                cout << "0\n";
            } else {
                cout << pos[v][k - 1] << '\n';
            }
        }
    }
}