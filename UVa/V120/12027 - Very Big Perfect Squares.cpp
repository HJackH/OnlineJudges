#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "0") {
        int len = s.length();
        int num = s[0] - '0';
        if (len >= 2 && len % 2 == 0) {
            num = num * 10 + s[1] - '0';
        }
        cout << int(sqrt(num)) << string((len - 1) / 2, '0') << "\n";
    }
}