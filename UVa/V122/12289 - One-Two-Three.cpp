#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    string one = "one";
    string two = "two";
    
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        if (s.length() == 5) {
            cout << "3\n";
            continue;
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0, ed = s.length(); i < ed; i++) {
            if (s[i] == one[i]) {
                cnt1++;
            }
            if (s[i] == two[i]) {
                cnt2++;
            }
        }
        if (cnt1 > cnt2) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}