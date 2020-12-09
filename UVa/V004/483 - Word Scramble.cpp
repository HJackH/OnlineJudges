#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define eb emplace_back

int main() { IOS
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<string> a;
        while (ss >> s) {
            reverse(s.begin(), s.end());
            a.eb(s);
        }
        bool first = 1;
        for (const auto &i : a) {
            if (!first) {
                cout << " ";
            }
            first = 0;
            cout << i;
        }
        cout << '\n';
    }
}