#include <bits/stdc++.h>
using namespace std;

int ans, tmp;
vector<int> a;
string input;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, input);
        stringstream ss(input);
        a.clear();
        ans = 1;
        while (ss >> tmp) {
            for (int i : a) {
                ans = max(ans, __gcd(i, tmp));
            }
            a.push_back(tmp);
        }
        cout << ans << '\n';
    }
}