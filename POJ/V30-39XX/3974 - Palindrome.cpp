#include <iostream>
#include <string>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1000000 + 5;

int p[2 * MAXN];
int Manacher(const string &str) {
    string tmp = "@#";
    for (int i = 0; i < str.length(); i++) {
        tmp += str[i];
        tmp += '#';
    }
    tmp += '$';
    int id = 0, mx = 0, ans = 0;
    for (int i = 1; i < tmp.length() - 1; i++) {
        p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
        for (; tmp[i - p[i]] == tmp[i + p[i]]; p[i]++);
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

int main() {
    IOS
    int kase = 0;
    string s;
    while (getline(cin, s) && s != "END") {
        cout << "Case " << ++kase << ": " << Manacher(s) << '\n';
    }
}