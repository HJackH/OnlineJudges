#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n, m, num;
string s;
unordered_map<string, int> M;

int main() {
    IOS
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> s >> num;
        M[s] = num;
    }
    for (int i = 0; i < n; i++) {
        long long ans = 0;
        while (cin >> s && s != ".") {
            if (M.count(s)) {
                ans += M[s];
            }
        }
        cout << ans << '\n';
    }
}