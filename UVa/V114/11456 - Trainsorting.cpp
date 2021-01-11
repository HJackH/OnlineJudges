#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 2000 + 5;

int n, a[MAXN * 2];

int LIS() {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || ans.back() < a[i]) {
            ans.push_back(a[i]);
        } else {
            *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
        }
    }
    return ans.size();
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        // add reversed array to the front
        // a = 1, 2, 3
        // a -> 3, 2, 1, 1, 2, 3
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i + n] = a[i];
        }
        reverse(a, a + n);

        // now array have 2n elements
        n *= 2;
        cout << LIS() << '\n';        
    }
}