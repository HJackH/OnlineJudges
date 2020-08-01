#include <bits/stdc++.h>
using namespace std;

long long n;
unordered_set<long long> S;

int main() {
    while (cin >> n && n) {
        cout << "Original number was " << n << '\n';
        S.clear();
        string s1, s2;
        int cnt = 0;
        while (1) {
            s1 = to_string(n);
            s2 = s1;
            cnt++;
            sort(s1.begin(), s1.end(), greater<char>());
            sort(s2.begin(), s2.end(), less<char>());
            //s2 may exist prefix 0
            cout << s1 << " - " << (n = stol(s2)) << " = " << (n = stol(s1) - n) << '\n';
            if (S.count(n)) {
                break;
            } else {
                S.insert(n);
            }
        }
        cout << "Chain length " << cnt << "\n\n";
    }
}