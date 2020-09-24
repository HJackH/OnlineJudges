#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 2e5 + 5;

int n, p[MAXN];

int main() {
    IOS

    cin >> n;
    p[0] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> ans;
    for (int i = n; p[i] != -1; i = p[i]) {
        ans.push_back(i);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i != ans.size() - 1) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}