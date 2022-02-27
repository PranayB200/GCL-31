#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// This function returns the maximum linear path sum starting at the current node.
int max_linear_path_sum(Node *root, int &res) {
    if (root == NULL) {
        return 0;
    }

    // `l` is the maximum linear path sum starting at the current node and moving towards left.
    // `r` is the maximum linear path sum starting at the current node and moving towards right.
    int l = root->data + max_linear_path_sum(root->left, res);
    int r = root->data + max_linear_path_sum(root->right, res);

    res = max({res, root->data, l, r, l + r - root->data});

    return max({root->data, l, r});
}

int max_path_sum(Node *root) {

    int result = root->data;
    int temp = max_linear_path_sum(root, result);
    return result;
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(-1);

    cout << max_path_sum(root) << endl;
}