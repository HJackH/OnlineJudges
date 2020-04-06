#include <bits/stdc++.h>
using namespace std;

string input;
stringstream ss;
set<string> S;

int main() {
    while (cin >> input) {
        int sz = input.length(), i = 0, j = sz - 1;
        while (!isalpha(input[i])) i++;
        while (!isalpha(input[j])) j--;

        if (i > j) {
            continue;
        }

        string tmp;
        for (int k = i; k <= j; k++) {
            if (!isalpha(input[k])) {
                if (tmp.size()) {
                    S.insert(tmp);
                }
                tmp.clear();
            } else {
                tmp.push_back(tolower(input[k]));
            }
        }
        if (tmp.size()) {
            S.insert(tmp);
        }
    }
    for (auto i = S.begin(); i != S.end(); i++) {
        cout << *i << '\n';
    }
}