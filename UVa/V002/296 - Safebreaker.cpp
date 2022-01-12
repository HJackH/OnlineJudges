#include <bits/stdc++.h>
using namespace std;
const int MAXG = 10 + 5;

struct Guess {
    string str;
    int x;
    int y;
};

int n;
Guess g[MAXG];
string now(4, 0);
bool vis_now[4], vis_g[4];
vector<string> ans;

bool judge() {
    int xcnt, ycnt;
    for (int i = 0; i < n; i++) {
        xcnt = ycnt = 0;

        // check equal (x value)
        for (int j = 0; j < 4; j++) {
            if (now[j] == g[i].str[j]) {
                vis_now[j] = vis_g[j] = 1;
                xcnt++;
            } else {
                vis_now[j] = vis_g[j] = 0;
            }
        }

        // check wrong place (y value)
        for (int j = 0; j < 4; j++) {
            if (vis_now[j]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                if (vis_g[k]) {
                    continue;
                }
                if (now[j] == g[i].str[k]) {
                    vis_g[k] = 1;
                    ycnt++;
                    break;
                }
            }
        }

        if (xcnt != g[i].x || ycnt != g[i].y) {
            return false;
        }
    }
    return true;
}

void dfs(int l) {
    if (l == 4) {
        if (judge()) {
            ans.emplace_back(now);
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        now[l] = i + '0';
        dfs(l + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        char c;
        for (int i = 0; i < n; i++) {
            cin >> g[i].str >> g[i].x >> c >> g[i].y;
        }

        ans.clear();
        dfs(0);
        
        if (ans.size() == 0) {
            cout << "impossible\n";
        } else if (ans.size() > 1) {
            cout << "indeterminate\n";
        } else {
            cout << ans[0] << "\n";
        }
    }
}