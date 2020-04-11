#include <bits/stdc++.h>
using namespace std;

string input;

int main() {
    while (cin >> input && input != "#") {
        if (next_permutation(input.begin(), input.end())) {
            cout << input << '\n';
        } else {
            cout << "No Successor\n";
        }
    }
}