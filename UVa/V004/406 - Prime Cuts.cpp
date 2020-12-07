#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1000 + 20;

int n, c;
vector<int> p;

void table() {
    vector<bool> vis(MAXN + 5, 0);
    for (int i = 2; i <= MAXN; i++) {
        if (!vis[i]) {
            p.pb(i);
        }
        for (int j : p) {
            if (i * j > MAXN) {
                break;
            }
            vis[i * j] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
    p.insert(p.begin(), 1);
}

int main() { IOS
    table();
    while (cin >> n >> c) {
        int total = upper_bound(p.begin(), p.end(), n) - p.begin();
        int mid = total >> 1;
        int l = max(0, mid - c + (total & 1)), r = min(total, mid + c);
        
        vector<int> ans(r - l);
        copy(p.begin() + l, p.begin() + r, ans.begin());
        
        cout << n << ' ' << c << ':';
        for (int i : ans) {
            cout << ' ' << i;
        }
        cout << "\n\n";
    }
}