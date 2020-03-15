#include <bits/stdc++.h>
using namespace std;

long long T, s, d;

int main() {
    cin >> T;
    while (T--) {
        cin >> s >> d;
        if (s < d || (s + d) & 1) {
            cout << "impossible\n";
            continue;
        }
        cout << (s + d) / 2 << ' ' << (s - d) / 2 << '\n';
    }
}
