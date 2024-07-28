#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool FindNode(BinaryTreeNode<int>* root, int nodeData) {
    // If the tree is empty then node is not found.
    if(root == NULL) return false;

    // If the root is the node then return true
    if(root->data == nodeData) return true;

    // return true if the node is found in either left sub tree or right sub tree
    return FindNode(root->left, nodeData) || FindNode(root->right, nodeData);
}

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

// 1 2 3 5 6 -1 4 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    cout << FindNode(root, 7);
    delete root;
    return 0;
}