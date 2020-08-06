#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 10000 + 5;

struct Node {
    char alp;
    Node* lc;
    Node* rc;
};

int k;
string str;
Node pool[MAXN + 100];
stack<Node*> st;
queue<Node*> q;
vector<char> ans;

int main() {
    IOS
    ans.reserve(MAXN);
    int T;
    cin >> T;
    while (T--) {
        k = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (isupper(c)) {
                Node* now = &pool[k++];
                now->alp = c;
                now->rc = st.top();
                st.pop();
                now->lc = st.top();
                st.pop();
                st.push(now);
            } else {
                Node* now = &pool[k++];
                now->alp = c;
                now->lc = NULL;
                now->rc = NULL;
                st.push(now);
            }
        }

        ans.clear();
        Node* root = st.top();
        st.pop();
        q.push(root);
        while (!q.empty()) {
            Node* now = q.front();
            q.pop();
            ans.push_back(now->alp);
            if (now->lc) {
                q.push(now->lc);
            }
            if (now->rc) {
                q.push(now->rc);
            }    
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << '\n';
    }
}