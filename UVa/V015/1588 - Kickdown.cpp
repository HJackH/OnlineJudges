#include <bits/stdc++.h>
using namespace std;

int cmp(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    int ans = n + m;
    for (int i = 0; i < n; i++) {
        bool match = 1;
        for (int j = 0; j < m && i + j < n; j++) {
            if (s1[i + j] + s2[j] >= '2' + '2') {
                match = 0;
                break;
            }
        }
        if (match) {
            ans = min(ans, max(n, m + i));
        }
    }
    return ans;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << min(cmp(s1, s2), cmp(s2, s1)) << "\n";
    }
}