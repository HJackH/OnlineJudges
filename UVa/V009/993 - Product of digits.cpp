#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int n;

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> ans;
        if (n <= 1) {
            ans.pb(n);
        } else {
            for (int i = 9; i >= 2; i--) {
                while (n % i == 0) {
                    ans.pb(i);
                    n /= i;
                }
            }
        }

        if (n > 1) {
            cout << "-1\n";
        } else {
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i];
            }
            cout << '\n';
        }
    }
}