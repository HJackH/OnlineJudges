#include <bits/stdc++.h>
using namespace std;

string input;

string G(string str) {
    int sum = 0, len = str.length();
    if (len == 1) {
        return str;
    }

    for (int i = 0; i < len; i++) {
        sum += str[i] - '0';
    }
    return G(to_string(sum));
}

int main() {
    while (cin >> input && input != "0") {
        cout << G(input) << '\n';
    }
}
