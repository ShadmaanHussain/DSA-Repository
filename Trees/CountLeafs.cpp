#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

int CountLeafs(TreeNode<int>* root) {
    if(root->children.size() == 0) return 1;

    int leafs = 0;
    for(TreeNode<int>* child : root->children) {
        leafs += CountLeafs(child);
    }
    return leafs;
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
         << "Printing No of Leafs: " << CountLeafs(root);
    delete root;
    return 0;
}