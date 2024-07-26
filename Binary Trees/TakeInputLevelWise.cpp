#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* TakeInputLevelWise() {
    queue<BinaryTreeNode<int>*> nodes;
    int nodeData;

    cout << "Enter Node: " << endl;
    cin >> nodeData;

    if(nodeData == -1) return NULL;

    BinaryTreeNode<int>* rootNode = new BinaryTreeNode<int>(nodeData);
    nodes.push(rootNode);

    while(!nodes.empty()) {
        BinaryTreeNode<int>* current = nodes.front();
        int leftChild, rightChild;
        cout << "Enter the left Child of node " << current-> data << " :" << endl;
        cin >> leftChild;
        cout << "Enter the right Child of node " << current-> data << " :" << endl;
        cin >> rightChild;

        if(leftChild != -1) {
            BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChild);
            current->left = leftChildNode;
            nodes.push(leftChildNode);
        }

        if(rightChild != -1) {
            BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChild);
            current->right = rightChildNode;
            nodes.push(rightChildNode);
        }

        nodes.pop();
    }

    return rootNode;
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
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    PrintBinaryTree(root);
    delete root;
    return 0;
}