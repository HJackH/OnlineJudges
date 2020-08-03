#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

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
bool first;
Node pool[MAXN + 500];

void insert(Node* &root, int num) {
    if (root == NULL) {
        root = &pool[k++];
        root->init(num);
        return;
    }
    if (num <= root->val) {
        insert(root->lc, num);
    } else {
        insert(root->rc, num);
    }
}

void dfs(Node* &root) {
    if (root == NULL) {
        return;
    }
    if (!first) {
        cout << ' ';
    }
    first = false;
    cout << root->val;
    dfs(root->lc);
    dfs(root->rc);
}

int main() {
    while (cin >> n) {
        k = 0;
        Node* root = NULL;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            insert(root, num);
        }   

        first = true;
        dfs(root);
        cout << '\n';
    }
}