#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void print(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// first is the head and second is the tail
pair<Node*, Node*> BSTtoLL(BinaryTreeNode<int>* root) {
    pair<Node*, Node*> ans;
    if(root == NULL) {
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }

    Node* node = new Node(root->data);

    pair<Node*,Node*> left = BSTtoLL(root->left);
    pair<Node*,Node*> right = BSTtoLL(root->right);

    if(left.first) left.second->next = node;
    if(right.first) node->next = right.first;

    ans.first = left.first ? left.first : node;
    ans.second = right.first ? right.second : node;

    return ans;
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
    print(BSTtoLL(root).first);
    delete root;
    return 0;
}