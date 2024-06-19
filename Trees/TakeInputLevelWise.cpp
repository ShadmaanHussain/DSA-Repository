#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

// Taking input of tree one level at a time
TreeNode<int> *TakeInputLevelWise()
{
    queue<TreeNode<int> *> trackNodes;
    int data;
    cout << "Enter root of tree: " << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    trackNodes.push(root);
    while (trackNodes.size() != 0)
    {
        TreeNode<int> *currentNode = trackNodes.front();
        int noChild;
        trackNodes.pop();
        cout << "Enter no of children of " << currentNode->data << endl;
        cin >> noChild;
        for (int i = 0; i < noChild; i++)
        {
            int child;
            cout << "Enter data for the " << i + 1 << "st child: " << endl;
            cin >> child;
            TreeNode<int> *childNode = new TreeNode<int>(child);
            currentNode->children.push_back(childNode);
            trackNodes.push(childNode);
        }
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
    TreeNode<int> *root = TakeInputLevelWise();
    cout << endl
         << "Printing Tree: " << endl;
    PrintTree(root);

    delete root;
    return 0;
}