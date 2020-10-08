#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define eb emplace_back
#define pb push_back
const int MAXN = 1e5 + 5;

int cnt[MAXN], k = 0;
unordered_map<string, int> M;

int main() { IOS
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (M.count(s)) {
            cout << s << to_string(++cnt[M[s]]) << '\n';
        } else {
            M[s] = k++;
            cout << "OK\n";
        }
    }
}