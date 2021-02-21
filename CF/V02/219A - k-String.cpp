#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int k;
string s;

int main() { IOS
    cin >> k >> s;
    vector<int> cnt(26 + 5, 0);
    for (auto c : s) {
        ++cnt[c - 'a'];
    }

    string ans;
    ans.reserve(s.length() / k);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % k != 0) {
            cout << "-1\n";
            return 0;
        }
        ans += string(cnt[i] / k, 'a' + i);
    }
    
    for (int i = 0; i < k; i++) {
        cout << ans;
    }
    cout << '\n';
}