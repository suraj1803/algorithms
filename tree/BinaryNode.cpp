#include <cstddef>
#include <iostream>
using namespace std;

template <typename T> class BinaryNode {
  private:
    void subTreeIterHelper(bool isOriginal) {
        if (this->left) {
            this->left->subTreeIterHelper(false);
        }

        cout << this->item << " ";

        if (this->right) {
            this->right->subTreeIterHelper(false);
        }

        if (isOriginal) {
            cout << "\n";
        }
    }

  public:
    T item;
    BinaryNode<T> *parent;
    BinaryNode<T> *left;
    BinaryNode<T> *right;

    BinaryNode(T item) {
        this->item = item;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    void subTreeIter() { this->subTreeIterHelper(true); }

    BinaryNode<T> *subTreeFirst() {
        if (this->left) {
            return this->left->subTreeFirst();
        }
        return this;
    }

    BinaryNode<T> *subTreeLast() {
        if (this->right) {
            return this->right->subTreeLast();
        }
        return this;
    }

    /*
     * the second case is to return the closest ancestor for which
     * the given node comes to it's left subTree
     */

    BinaryNode<T> *successor() {
        if (this->right) {
            return this->right->subTreeFirst();
        }

        BinaryNode<T> *current = this;
        while (current->parent != NULL && current->parent->right == current) {
            current = current->parent;
        }

        return current->parent;
    }

    /*
     * the second case is to return the closest descendent for which
     * the given node comes to it's left subTree
     */

    BinaryNode<T> *predecessor() {
        if (this->left) {
            return this->left->subTreeLast();
        }

        BinaryNode<T> *current = this;
        while (current->parent != NULL && current->parent->left == current) {
            current = current->parent;
        }
        return current->parent;
    }

    void subTreeInsertBefore(BinaryNode<T> *node) {
        if (this->left) {
            auto predecessor = this->predecessor();
            predecessor->right = node;
            node->parent = predecessor;
        } else {
            this->left = node;
            node->parent = this;
        }
    }

    void subTreeInsertAfter(BinaryNode<T> *node) {
        if (this->right) {
            auto successor = this->successor();
            successor->left = node;
            node->parent = successor;
        } else {
            this->right = node;
            node->parent = this;
        }
    }

    friend ostream &operator<<(ostream &out, const BinaryNode<T> &node) {
        out << node.item;
        return out;
    }

    friend ostream &operator<<(ostream &out, const BinaryNode<T> *node) {
        if (node == NULL)
            out << "null";
        else
            out << node->item;

        return out;
    }
};

int main(int argc, char *argv[]) {
    BinaryNode<int> *root = new BinaryNode<int>(10);
    root->left = new BinaryNode<int>(5);
    root->left->parent = root;
    root->right = new BinaryNode<int>(15);
    root->right->parent = root;
    root->subTreeIter();
    // cout << root->subTreeFirst() << " " << root->subTreeLast() << endl;
    // cout << root->subTreeFirst() << endl;
    // cout << "successor of root : " << root->successor() << endl;
    // cout << "predecessor of root : " << root->predecessor() << endl;
    // cout << root->left->predecessor() << endl;

    auto node = new BinaryNode<int>(1);
    root->subTreeInsertBefore(node);

    auto node1 = new BinaryNode<int>(2);
    root->subTreeInsertAfter(node1);
    root->subTreeIter();
    cout << root->predecessor() << endl;
    cout << root->successor() << endl;

    free(root->left);
    free(root->right);
    free(root);
    free(node);
    free(node1);

    return 0;
}
