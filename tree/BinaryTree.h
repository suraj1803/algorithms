#include "BinaryNode.h"
#include <vector>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    BinaryNode<T> *root;
    int nodes;
    BinaryNode<T> *buildTree(std::vector<T> &arr, int i, int j)
    {
        if (i <= j)
        {
            int root_index = (i + j) / 2;
            BinaryNode<T> *root = new BinaryNode<T>(arr[root_index]);

            BinaryNode<T> *left_node = buildTree(arr, i, root_index - 1);
            BinaryNode<T> *right_node = buildTree(arr, root_index + 1, j);

            root->left = left_node;
            root->right = right_node;

            if (left_node != NULL)
                left_node->parent = root;
            if (right_node != NULL)
                right_node->parent = root;

            return root;
        }
        else
        {
            return NULL;
        }
    }

public:
    BinaryTree()
    {
        root = nullptr;
        nodes = 0;
    }


    void buildTree(std::vector<T> &arr)
    {
        this->root = buildTree(arr, 0, arr.size() - 1);
        this->nodes = arr.size();
    }

    int size()
    {
        return nodes;
    }

    void treeIter()
    {
        if (root)
        {
            root->subTreeIter();
        }
    }

    ~BinaryTree()
    {
        if (root)
            root->freeMemorySubtree();
    }
};

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BinaryTree<int> tree;
    tree.buildTree(arr);
    tree.treeIter();
    cout << tree.size() << endl;

    return 0;
}
