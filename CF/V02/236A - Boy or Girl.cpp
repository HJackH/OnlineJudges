#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) (int((x).size()))

int main() { IOS
    string s;
    cin >> s;

    set<char> st;
    for (char c : s) {
        st.insert(c);
    }

    if (st.size() & 1) {
        cout << "IGNORE HIM!\n";
    } else {
        cout << "CHAT WITH HER!\n";
    }
}