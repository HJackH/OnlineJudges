#include <bits/stdc++.h>
using namespace std;

int T, n;
string input;
map<string, int> M;

int main() {
    cin >> T;
    cin.ignore(1);
    getline(cin, input);

    for (int t = 0; t < T; t++) {
        n = 0;
        M.clear();

        while (getline(cin, input) && input.length() > 0) {
            if (M.find(input) == M.end()) {
                M[input] = 1;
            } else {
                M[input]++;
            }
            n++;
        }

        for (auto i = M.begin(); i != M.end(); i++) {
            cout << i -> first << ' ';
            printf("%.4lf\n", (double)(i -> second) * 100 / n);
        }
        if (t != T - 1) {
            cout << '\n';    
        }
    }
}