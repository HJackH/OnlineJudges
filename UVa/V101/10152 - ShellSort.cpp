#include <bits/stdc++.h>
using namespace std;

struct Turtle {
    string name;
    int rnk;

    Turtle() {
        rnk = 0;
    }
    Turtle(string _name, int _rnk) {
        name = _name;
        rnk = _rnk;
    }
};

int T, n;

int main() {
    Turtle tmp;

    cin >> T;
    while (T--) {
        vector<Turtle> origin, order;

        cin >> n;
        getline(cin, tmp.name);
        for (int i = 0; i < n; i++) {
            getline(cin, tmp.name);
            origin.push_back(Turtle(tmp.name, 0));
        }

        for (int i = 0; i < n; i++) {
            getline(cin, tmp.name);
            order.push_back(Turtle(tmp.name, i));
            for (int j = 0; j < n; j++) {
                if (tmp.name == origin[j].name) {
                    origin[j].rnk = i;
                    break;
                }
            }
        }

        int level = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (origin[i].rnk == level) {
                level--;
            }
        }

        for (int i = level; i >= 0; i--) {
            cout << order[i].name << endl;
        }
        cout << endl;
    }
}
