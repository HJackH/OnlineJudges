#include <bits/stdc++.h>
using namespace std;

int T;
string str;

int main() {
    cin >> T;
    while (T--) {
        cin >> str;
        sort(str.begin(), str.end());
        do
        {
            cout << str << '\n';
        } while (next_permutation(str.begin(), str.end()));
        cout << '\n';
    }
}