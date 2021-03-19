#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e6 + 5;

struct Space {
    int floor;
    int ceil;
    int h1;
    int h2;
};

int n;
Space spaces[MAXN];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> spaces[i].floor;
        }
        for (int i = 0; i < n; i++) {
            cin >> spaces[i].ceil;
        }

        // scan from left
        int lv = spaces[0].ceil;
        for (int i = 0; i < n; i++) {
            lv = min(lv, spaces[i].ceil);
            lv = max(lv, spaces[i].floor);
            spaces[i].h1 = lv;
        }
        // scan from right
        lv = spaces[n - 1].ceil;
        for (int i = n - 1; i >= 0; i--) {
            lv = min(lv, spaces[i].ceil);
            lv = max(lv, spaces[i].floor);
            spaces[i].h2 = lv;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(spaces[i].h1, spaces[i].h2) - spaces[i].floor;
        }
        cout << ans << '\n';
    }
}