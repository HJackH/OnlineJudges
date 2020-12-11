#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int lb[256];
string s;

bool isPair(char a, char b) {
    if (a == '(') {
        return b == ')';
    } else {
        return (b - a) == 2;
    }
}

int main() { IOS
    lb['<'] = lb['{'] = lb['['] = lb['('] = 1;
    lb['>'] = lb['}'] = lb[']'] = lb[')'] = 2;

    cin >> s;

    int ans = 0;
    deque<char> dq;
    for (auto &c : s) {
        if (lb[c] == 1) {   // opening
            dq.pb(c);
        } else {            // closing
            if (dq.empty() || lb[dq.back()] != 1) {
                cout << "Impossible\n";
                return 0;
            }
            if (!isPair(dq.back(), c)) {
                ++ans;
            }
            dq.pop_back();
        }
    }
    
    if (!dq.empty()) {
        cout << "Impossible\n";
    } else {
        cout << ans << '\n';
    }
}