#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int INF = 1e9;
const int MAXN = 26;

int G[MAXN][MAXN], has[MAXN], ansBand;
vector<int> a, ans;

void solve() {
    do {
        int aBand = 0;
        
        for (int i = 0; i < a.size(); i++) {
            int iBand = 0;
            for (int j = i + 1; j < a.size(); j++) {
                if (G[a[i]][a[j]]) {
                    iBand = max(iBand, abs(i - j));
                }
            }
            aBand = max(aBand, iBand);
            if (aBand >= ansBand) {
                break;
            }
        }

        if (ansBand > aBand) {
            ansBand = aBand;
            ans = a;
        }
    } while (next_permutation(a.begin(), a.end()));
}

int main() { IOS
    string input;
    while (cin >> input && input != "#") {
        memset(G, 0, sizeof(G));
        memset(has, 0, sizeof(has));

        int st, to;
        for (int i = 0; i < input.size(); i++) {
            st = input[i] - 'A';
            has[st] = 1;
            // ignore 'st' and ':' 
            for (i += 2; i < input.size() && input[i] != ';'; i++) {
                to = input[i] - 'A';
                G[st][to] = G[to][st] = 1;
                has[to] = 1;
            }
        }

        a.clear();
        for (int i = 0; i < MAXN; i++) {
            if (has[i]) {
                a.push_back(i);
            }
        }

        ansBand = INF;
        ans.clear();
        solve();

        for (int i : ans) {
            cout << char(i + 'A') << ' ';
        }
        cout << "-> " << ansBand << '\n';
    }
}