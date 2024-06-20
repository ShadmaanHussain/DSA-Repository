#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void PrintNodesAtDepthK(TreeNode<int> *root, int depth)
{
    if (depth == 0)
    {
        cout << root->data << " ";
    }
    for (TreeNode<int> *child : root->children)
    {
        PrintNodesAtDepthK(child, depth - 1);
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
         << "Printing TreeNodes at Depth: " << endl;
    PrintNodesAtDepthK(root, 2);
    delete root;
    return 0;
}