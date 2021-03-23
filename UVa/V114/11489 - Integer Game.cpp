#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int main() { IOS
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        string s;
        cin >> s;
        cout << "Case " << kase << ": ";

        int sum = 0;
        vector<int> cnt(3, 0);
        for (char c : s) {
            cnt[(c - '0') % 3]++;
            sum += c - '0';
        }

        int ans = cnt[0];
        if (sum % 3 && cnt[sum % 3]) {
            ans++;
        }
        
        if (ans & 1) {
            cout << "S\n";
        } else {
            cout << "T\n";
        }
    }
}