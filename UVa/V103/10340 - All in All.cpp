#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string s1, s2;

int main() {
    IOS
    while (cin >> s1 >> s2) {
        int k = 0;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == s1[k]) {
                k++;
            }
        }
        if (k == s1.length()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}