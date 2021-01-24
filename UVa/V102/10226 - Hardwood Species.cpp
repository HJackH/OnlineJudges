#include <bits/stdc++.h>
using namespace std;

int T, n;
string input;
map<string, int> M;

int main() {
    cin >> T;
    cin.ignore(1);
    getline(cin, input);

    while (T--) {
        M.clear();
        n = 0;

        while (getline(cin, input) && input.length() > 0) {
            if (M.count(input)) {
                ++M[input];
            } else {
                M[input] = 1;
            }
            ++n;
        }

        for (auto i : M) {
            printf("%s %.4lf\n", i.first.c_str(), i.second * 100.0 / n);
        }

        if (T) {
            cout << '\n';
        }
    }
}