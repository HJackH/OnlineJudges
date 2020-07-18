#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    while (getline(cin, str)) {
        transform(str.begin(), str.end(), str.begin(), [](char c) -> char { return c - ('1' - '*'); });
        cout << str << '\n';
    }
}