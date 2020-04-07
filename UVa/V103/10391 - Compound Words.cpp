#include <bits/stdc++.h>
using namespace std;

string input;
set<string> In, Out;

int main() {
    while (getline(cin, input)) {
        In.insert(input);
    }

    for (auto i = In.begin(); i != In.end(); i++) {
        auto j = i;
        for (j++; (*j).substr(0, (*i).length()) == (*i); j++) {
            if (In.count((*j).substr((*i).length()))) {
                Out.insert(*j);
            }
        }
    }

    for (auto i : Out) {
        cout << i << '\n';
    }
}