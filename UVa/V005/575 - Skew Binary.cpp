#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "0") {
        int n = s.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            int e = n - i;
            sum += (s[i] - '0') * ((1 << e) - 1);
        }
        cout << sum << "\n";
    }
}