#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() { IOS
    string s;
    cin >> s;
    cout << (stoi(s, 0, 16) & 1) << '\n';
}