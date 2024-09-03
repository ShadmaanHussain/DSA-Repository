#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int HeightOfTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;

    return 1 + max(HeightOfTree(root->left), HeightOfTree(root->right));
}

int DiameterOfTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;

    int leftHeight = HeightOfTree(root->left);
    int rightHeight = HeightOfTree(root->right);

    int leftDiameter = DiameterOfTree(root->left);
    int rightDiameter = DiameterOfTree(root->right);

    return max(leftDiameter, max(rightDiameter, leftHeight + rightHeight));
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
    cout << DiameterOfTree(root);
    delete root;
    return 0;
}