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
        cout << "R" << root->right->data;
    }
    cout << endl;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}

BinaryTreeNode<int>* TakeInput() {
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;

    // We are doing this because if we ask user several times if left exists or right exists it will be cumbersome for the user.
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(rootData);

    newNode->left = TakeInput();
    newNode->right = TakeInput();

    return newNode;
}

    //      1
    //     / \
    //    2   3
    // Input for the above tree
    // 1 2 -1 -1 3 -1 -1
int main() {
    BinaryTreeNode<int>* root = TakeInput();
    PrintBinaryTree(root);
    delete root;
    return 0;
}