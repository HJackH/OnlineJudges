#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

const string mp = "22233344455566677778889999";

int main() { IOS
    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            if (c == '-' || isdigit(c)) {
                cout << c;
            } else {
                cout << mp[c - 'A'];
            }
        }
        cout << '\n';
    }
}