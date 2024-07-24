#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
 
void PrintBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;

    cout << root->data << ": ";

    if(root->left) {
        cout << "L" << root->left->data << " ";
    }
    if(root->right) {
        cout << "R" << root->right->data << endl;
    }

    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}

int main() {
    cout << "Hello World";
    return 0;
}