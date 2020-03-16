#include <bits/stdc++.h>
using namespace std;

int T;
string input;

bool isPair(char c1, char c2) {
    if (c1 == '[' && c2 == ']') {
        return true;
    }
    if (c1 == '(' && c2 == ')') {
        return true;
    }
    return false;
}

int main() {
    cin >> T;
    cin.ignore(1);
    while (T--) {
        getline(cin, input);
        
        stack<char> st;
        int len = input.length();
        bool chk = true;

        int i;
        for (i = 0; i < len && chk; i++) {
            if (input[i] == '[' || input[i] == '(') {
                st.push(input[i]);
            } else {
                chk = !st.empty() && isPair(st.top(), input[i]);
                if (chk) {
                    st.pop();
                }
            }
        }


        if (chk && st.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
