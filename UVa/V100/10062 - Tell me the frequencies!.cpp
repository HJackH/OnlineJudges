#include <bits/stdc++.h>
using namespace std;

const int MAXN = 256;

struct Alp {
    int id;
    int cnt;
    bool operator < (const Alp &other) const {
        if (cnt == other.cnt) {
            return id > other.id;
        }
        return cnt < other.cnt;
    }
};

Alp alps[MAXN];
string str;

int main() {
    bool first = true;
    while (getline(cin, str)) {
        if (!first) {
            cout << '\n';
        }
        first = false;
        
        for (int i = 32; i < 128; i++) {
            alps[i] = {i, 0};
        }
        for (char c : str) {
            alps[c].cnt++;
        }
        sort(alps + 32, alps + 128);
        for (int i = 32; i < 128; i++) {
            if (alps[i].cnt == 0) {
                continue;
            }
            cout << alps[i].id << ' ' << alps[i].cnt << '\n';
        }
    }
}