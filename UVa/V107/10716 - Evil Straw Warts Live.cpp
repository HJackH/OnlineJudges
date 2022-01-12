#include <bits/stdc++.h>
using namespace std;
const int MAXC = 26 + 5;

string s;
int n, cnt[MAXC];

int sol() {
    int chk = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            if (n & 1) {
                if (++chk > 1) {
                    return -1;
                }
            } else {
                return -1;
            }
        }
    }

    int ans = 0;
    for (int i = 0, ed = n / 2; i < ed; i++) {
        int j = n - i - 1;
        if (s[i] == s[j]) {
            continue;
        }

        // i fixed
        int k;
        for (k = j; k > i; k--) {
            if (s[i] == s[k]) {
                break;
            }
        }

        // j fixed
        int l;
        for (l = i; l < j; l++) {
            if (s[j] == s[l]) {
                break;
            }
        }

        if (j - k <= l - i) {
            ans += j - k;
            for (; k < j; k++) {
                swap(s[k], s[k + 1]);
            }
        } else {
            ans += l - i;
            for (; l > i; l--) {
                swap(s[l - 1], s[l]);
            }
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        memset(cnt, 0, sizeof(cnt));
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int ans = sol();
        if (ans == -1) {
            cout << "Impossible\n";
        } else {
            cout << ans << "\n";
        }
    }
}