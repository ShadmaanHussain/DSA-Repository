#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

class BSTReturn {
    public:
    bool isBST;
    int max;
    int min;
};

BSTReturn isBSTOptimized(BinaryTreeNode<int>* root) {
    BSTReturn output;
    if(root == NULL) {
        output.isBST = true;
        output.max = INT_MIN;
        output.min = INT_MAX;
        return output;
    }

    BSTReturn leftOutput = isBSTOptimized(root->left);
    BSTReturn rightOutput = isBSTOptimized(root->right);

    output.max = max(root->data, max(leftOutput.max, rightOutput.max));
    output.min = min(root->data, min(leftOutput.min, rightOutput.min));
    output.isBST = root->data > leftOutput.max && root->data <= rightOutput.min && leftOutput.isBST && rightOutput.isBST;

    return output;
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
    cout << isBSTOptimized(root).isBST;
    delete root;
    return 0;
}