#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    int num;
    int end;
    node *child[26];

    node() {
        num = 0;
        end = 0;
        memset(child, NULL, sizeof(child));
    }
};

node *tree;
int temp;

void insert(string str) {
    if (str.empty()) return;
    node *root = tree;
    for (int i = 0; i < str.length(); ++i) {
        temp = str[i] - 'a';
        if (root->child[temp] == NULL) {
            root->child[temp] = new node;
        }
        root = root->child[temp];
        root->num++;
    }
}

int prefix(string pre) {
    if (pre.empty()) return 0;
    node *root = tree;
    for (int i = 0; i < pre.length(); ++i) {
        temp = pre[i] - 'a';
        if (root->child[temp] == NULL) {
            return 0;
        }
        root = root->child[temp];
    }
    return root->num;
}

int main() {
    int n;
    tree = new node;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        insert(str);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        cout << prefix(str) << endl;
    }

    return 0;
}