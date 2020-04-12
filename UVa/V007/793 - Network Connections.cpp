#include <bits/stdc++.h>
using namespace std;

int T, n;
vector<int> parent;

int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (parent[a] > parent[b]) {
            swap(a, b);
        }
        parent[a] += parent[b];
        parent[b] = a;
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        parent.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            parent[i] = -1;
        }

        char mode;
        int a, b, cnt1 = 0, cnt2 = 0;
        string input;
        stringstream ss;
        cin.ignore(1);
        while (getline(cin, input) && input != "") {
            ss.str("");
            ss.clear();
            ss << input;
            ss >> mode >> a >> b;
            switch (mode)
            {
            case 'c':
                unionSet(a, b);
                break;

            case 'q':
                if (find(a) == find(b)) {
                    cnt1++;
                } else {
                    cnt2++;
                }
                break;
            
            default:
                break;
            }
        }
        cout << cnt1 << "," << cnt2 << "\n";
        if (T) {
            cout << "\n";
        }
    }
}