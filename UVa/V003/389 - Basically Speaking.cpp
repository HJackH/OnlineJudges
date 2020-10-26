#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pf push_front

int from, to;
string s;

int toNum(char c) {
    if (c >= 'A') {
        return c - 'A' + 10;
    }
    return c - '0';
}

char toChar(int n) {
    if (n >= 10) {
        return 'A' + n - 10;
    }
    return '0' + n;
}

int main() { IOS
    while (cin >> s >> from >> to) {
        int num = 0;
        for (char c: s) {
            num = num * from + toNum(c);
        }

        deque<char> ans;
        while (1) {
            ans.pf(toChar(num % to));
            num /= to;
            if (!num) {
                break;
            }
        }

        if (ans.size() > 7) {
            cout << "  ERROR\n";
        } else {
            for (int i = 6 - ans.size(); i >= 0; i--) {
                cout << ' ';
            }
            for (char c: ans) {
                cout << c;
            }
            cout << '\n';
        }
    }
}