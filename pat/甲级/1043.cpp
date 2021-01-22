#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct node {
    int data;
    node *left, *right;
};

void insert(node *&root, int data) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data) insert(root->left, data);
    else insert(root->right, data);
}

void preOrder(node *root, vector<int> &vi) {
    if (root == NULL)return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node *root, vector<int> &vi) {
    if (root == NULL)return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node *root, vector<int> &vi) {
    if (root == NULL)return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node *root, vector<int> &vi) {
    if (root == NULL)return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

void pat1043() {
    int n, data;
    node *root = NULL;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre) {
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            cout << post[i];
            if (i < post.size() - 1) cout << " ";
        }
    } else if (origin == preM) {
        printf("YES\n");
        for (int i = 0; i < postM.size(); ++i) {
            cout << postM[i];
            if (i < postM.size() - 1) cout << " ";
        }
    } else {
        cout << "NO\n";
    }
}


//int main() {
//    pat1043();
//    return 0;
//}