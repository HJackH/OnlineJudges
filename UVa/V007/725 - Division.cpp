#include <bits/stdc++.h>
using namespace std;

const int MAXN = 79;

struct Num {
    string up;
    string down;
};

bool vis[10 + 5];
vector<Num> a[MAXN + 5];

void solve() {
    for (int n = 2; n <= MAXN; n++) {
        for (int i = 1234; i * n <= 98765; i++) {
            memset(vis, 0, sizeof(vis));
            int down = i, up = i * n;
            if (down < 10000) {
                vis[0] = true;
                if (up < 10000) {
                    continue;
                }
            }
            
            bool chk = true;
            while (down) {
                if (vis[down % 10]) {
                    chk = false;
                    break;
                }
                vis[down % 10] = true;
                down /= 10;
            }

            while (chk && up) {
                if (vis[up % 10]) {
                    chk = false;
                    break;
                }
                vis[up % 10] = true;
                up /= 10;
            }
            
            if (chk) {
                string strd = to_string(i), stru = to_string(i * n);
                if (strd.length() == 4) {
                    strd = "0" + strd;
                }
                a[n].push_back({stru, strd});
            }
        }
    }
    
}

int main() {
    solve();

    int n;
    cin >> n;
    while (true) {
        if (a[n].size() == 0) {
            cout << "There are no solutions for " << n << ".\n";
        } else {
            for (auto i : a[n]) {
                cout << i.up << " / " << i.down << " = " << n << '\n';
            }
        }

        cin >> n;
        if (n) {
            cout << '\n';
        } else {
            break;
        }
    }
}