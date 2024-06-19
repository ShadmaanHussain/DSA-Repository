#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void PrintTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> trackNodes;
    trackNodes.push(root);
    while(!trackNodes.empty()) {
        TreeNode<int>* currentNode = trackNodes.front();
        trackNodes.pop();
        cout << currentNode->data << ": ";
        for(TreeNode<int>* child: currentNode->children) {
            cout << child->data << " ";
            trackNodes.push(child);
        }
        cout << endl;

    }
}

TreeNode<int> *TakeInput()
{
    int data;
    int noOfChildren;
    cout << "Enter the node: " << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    cout << "Enter number of children of " << root->data << endl;
    cin >> noOfChildren;
    for (int i = 0; i < noOfChildren; i++)
    {
        TreeNode<int> *childNode = TakeInput();
        root->children.push_back(childNode);
    }
    return root;
}

// 1 2 2 2 4 0 5 0 3 1 6 0
int main()
{
    TreeNode<int> *root = TakeInput();
    cout << endl
         << "Printing Tree: " << endl;
    PrintTreeLevelWise(root);
    delete root;
    return 0;
}