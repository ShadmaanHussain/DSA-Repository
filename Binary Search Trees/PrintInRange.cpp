#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void PrintInRange(BinaryTreeNode<int>* root, int min, int max) {
    if(root == NULL) return;

    if(root->data >= min && root->data <= max) {
        cout << root->data << " ";
        PrintInRange(root->left, min, max);
        PrintInRange(root->right, min, max);
        return;
    }

    if(root->data < min) {
        PrintInRange(root->right, min, max);
    }

    if(root->data > min) {
        PrintInRange(root->left, min, max);
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
    int min, max;
    cout << "Enter min & max: " << endl;
    cin >> min >> max;
    PrintInRange(root, min, max);
    delete root;
    return 0;
}