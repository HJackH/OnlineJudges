#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

struct Node {
    int val;
    Node* lc;
    Node* rc;
    void init(int _val) {
        val = _val;
        lc = NULL;
        rc = NULL;
    }
};

int n, k;
vector<char> route[MAXN];
Node pool[MAXN + 50];

void insert(Node* &root, int num, vector<char> &r) {
    if (root == NULL) {
        root = &pool[k++];
        root->init(num);
        route[num] = r;
        return;
    }
    if (num <= root->val) {
        r.emplace_back('E');
        insert(root->lc, num, r);
    } else {
        r.emplace_back('W');
        insert(root->rc, num, r);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        k = 0;
        Node* root = NULL;
        int num; 
        for (int i = 0; i < n; i++) {
            cin >> num;
            vector<char> r;
            insert(root, num, r);
        }

        int Q;
        cin >> Q;
        while (Q--) {
            cin >> num;
            for (auto c : route[num]) {
                cout << c;
            }
            cout << '\n';
        }
    }
}