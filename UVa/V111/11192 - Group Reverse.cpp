#include <bits/stdc++.h>
using namespace std;

int n;
string input;

int main() {
    while (cin >> n && n) {
        cin >> input;
        int len = input.length() / n;
        for (int i = 0; i < input.length(); i += len) {
            reverse(input.begin() + i, input.begin() + i + len);
        }
        cout << input << '\n';
    }
}