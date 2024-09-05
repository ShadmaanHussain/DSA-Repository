#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool FoundNode(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) return false;
    
    if(root->data == data) return true;

    if(data > root->data) return FoundNode(root->right, data);
    else return FoundNode(root->left, data);
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
    int data;
    cout << "Enter element to find: " << endl;
    cin >> data;
    cout << FoundNode(root, data);
    delete root;
    return 0;
}