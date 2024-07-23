using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data) {
        this->data = data;
        // By default left and right tree node should not contain garbage, we should initialize them to null
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        // If left and right nodes are null this will call delete NULL which is okay. It doesn't do anything we can call delete NULL
        delete left;
        delete right;
    }
};