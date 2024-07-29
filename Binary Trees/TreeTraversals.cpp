#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void InOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PreOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
	cout << root->data << " ";
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
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    delete root;
    return 0;
}