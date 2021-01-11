#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int INF = 1e9;
const int MAXN = 40 + 5;

int n;
int G[MAXN][MAXN];
bitset<MAXN> vis[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // i -> k -> j
                if (G[i][j] == G[i][k] + G[k][j]) {
                    vis[i][j][k] = 1;
                }
            }
        }
    }
}

int main() { IOS
    string input;
    while (cin >> n) {
        // for getline
        cin.ignore(1);

        for (int i = 1; i <= n; i++) {
            // init
            for (int j = 1; j <= n; j++) {
                G[i][j] = INF;
                vis[i][j].reset();
            }
            // self
            G[i][i] = 0;
            
            getline(cin, input);
            stringstream ss(input);
            int to;
            while (ss >> to) {
                G[i][to] = 1;
            }
        }

        floyd();

        int Q, num;
        vector<int> a;
        bitset<MAXN> ans;

        cin >> Q;
        // for getline
        cin.ignore(1);
        while (Q--) {
            getline(cin, input);
            stringstream ss(input);

            a.clear();
            while (ss >> num) {
                a.push_back(num);
            }

            ans.reset();
            for (int i = 0; i < a.size(); i++) {
                for (int j = i + 1; j < a.size(); j++) {
                    ans |= vis[a[i]][a[j]];
                }
            }

            // count 1 in ans
            if (ans.count() == n) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}