#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void PrintBinaryTreeLevelWise(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> nodes;

    if(root == NULL) return;

    nodes.push(root);

    while(!nodes.empty()) {
        BinaryTreeNode<int>* current = nodes.front();
        cout << current->data << ": ";

        if(current->left) {
            nodes.push(current->left);
            cout << "L" << current->left->data << " ";
        }
        if(current->right) {
            nodes.push(current->right);
            cout << "R" << current->right->data << " ";
        }
        cout << endl;

        nodes.pop();
    }
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

int main() {
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    PrintBinaryTreeLevelWise(root);
    delete root;
    return 0;
}