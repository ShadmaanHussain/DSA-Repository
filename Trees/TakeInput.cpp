#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

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

void PrintTree(TreeNode<int> *root)
{
    // No tree nothing to print
    if (root == NULL)
        return;

    cout << root->data << ": ";
    // Print every child data of the tree
    for (TreeNode<int> *child : root->children)
    {
        cout << child->data << " ";
    }
    cout << endl;
    // Print the child tree
    for (TreeNode<int> *child : root->children)
    {
        PrintTree(child);
    }
}

// 1 2 2 2 4 0 5 0 3 1 6 0
int main()
{
    TreeNode<int> *root = TakeInput();
    cout << endl
         << "Printing Tree: " << endl;
    PrintTree(root);
    delete root;
    return 0;
}