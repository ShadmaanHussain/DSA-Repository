#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* ConstructTree(vector<int> list, int start_i, int end_i) {
    if(end_i < start_i) return NULL;

    int mid = (start_i + end_i) / 2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(list[mid]);

    root->left = ConstructTree(list, start_i, mid - 1);
    root->right = ConstructTree(list, mid + 1, end_i);

    return root;
}

void PrintBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;

    cout << root->data << ": ";

    if(root->left) {
        cout << "L" << root->left->data << " ";
    }
    if(root->right) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}

int main() {
    vector<int> list {1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int>* root = ConstructTree(list, 0, list.size() - 1);
    PrintBinaryTree(root);
    delete root;
    return 0;
}