#include "BinaryNode.h"
#include <iostream>

using namespace std;

template <typename T>
class BSTNode : public BinaryNode<T>{
private:

public:
    BSTNode(T item) : BinaryNode<T>(item) {}

    BSTNode<T> *subtreeFind(T item) {
        if (this->item == item) {
            return this;
        }
        else if (item > this->item) {
            if (this->right) {
                return static_cast<BSTNode<T>*>(this->right)->subtreeFind(item);
            }
        }
        else {
            if (this->left) {
                return static_cast<BSTNode<T>*>(this->left)->subtreeFind(item);
            }
        }
        return nullptr;
    }



};

int main() {
    auto *root = new BSTNode<int>(10);
    root->left = new BSTNode<int>(5);
    root->right = new BSTNode<int>(15);
    root->left->parent = root;
    root->right->parent = root;

    cout << root->subtreeFind(15) << endl;

    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
