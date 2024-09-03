#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

pair<int,int> DiameterAndHeight(BinaryTreeNode<int>* root) {
    pair<int,int> ans(0,0);
    if(root == NULL) return ans;

    pair<int,int> leftDandH = DiameterAndHeight(root->left);
    pair<int,int> rightDandH = DiameterAndHeight(root->right);

    int leftD = leftDandH.first;
    int rightD = rightDandH.first;
    int leftH = leftDandH.second;
    int rightH = rightDandH.second;

    // diameter
    ans.first = max(leftD, max(rightD, leftH + rightH));
    // height
    ans.second = 1 + max(leftH, rightH);
    return ans;
}

int DiameterOfTree(BinaryTreeNode<int>* root) {
    return DiameterAndHeight(root).first;
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