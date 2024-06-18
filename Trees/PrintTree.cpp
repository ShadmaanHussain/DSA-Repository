#include <bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

void PrintTree(TreeNode<int> *root)
{
    // No tree nothing to print
    if(root == NULL) return;

    cout << root->data <<": ";
    // Print every child data of the tree
    for(TreeNode<int>* child : root->children) {
        cout << child->data << " ";
    }
    cout << endl;
    // Print the child tree
    for(TreeNode<int>* child : root->children) {
        PrintTree(child);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *two = new TreeNode<int>(2);
    TreeNode<int> *three = new TreeNode<int>(3);
    TreeNode<int> *four = new TreeNode<int>(4);
    TreeNode<int> *five = new TreeNode<int>(5);
    TreeNode<int> *six = new TreeNode<int>(6);
    TreeNode<int> *seven = new TreeNode<int>(7);
    TreeNode<int> *eight = new TreeNode<int>(8);
    root->children.push_back(two);
    root->children.push_back(three);
    root->children.push_back(four);
    two->children.push_back(five);
    two->children.push_back(six);
    three->children.push_back(seven);
    four->children.push_back(eight);

    PrintTree(root);

    delete root;
    return 0;
}