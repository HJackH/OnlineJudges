#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int INF = 1e9;
const int MAXN = 50 + 5;

int n, a[MAXN];
string b;

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> b;
        a[0] = 0;
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            if (b[i - 1] == '(') {
                a[i] = a[i - 1] + 1;
            } else {
                a[i] = a[i - 1] - 1;
            }
            ans = min(ans, a[i]);
        }
        cout << -ans << '\n';
    }
}