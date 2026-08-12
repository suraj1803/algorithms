#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class BinaryNode {
    private:
        void subtreeIterHelper(bool isOriginal) {
            if (this->left) {
                this->left->subtreeIterHelper(false);
            }

            cout << this->item << " "; 

            if (this->right) {
                this->right->subtreeIterHelper(false);
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

        void subtreeIter() {
            this->subtreeIterHelper(true);
        }


        BinaryNode<T>* subtreeFirst() {
            if (this->left) {
                return this->left->subtreeFirst();
            }
            return this;
        }

        BinaryNode<T>* subtreeLast() {
            if (this->right) {
                return this->right->subtreeLast();
            }
            return this;
        }

        BinaryNode<T>* successor() {
            if (this->right) {
                return this->right->subtreeFirst();
            }

            BinaryNode<T>* current = this;
            while (current->parent && current->parent->left != current) {
                current = current->parent;
            }
        }



        friend ostream& operator<<(ostream& out, const BinaryNode<T>& node) {
            out << node.item;
            return out;
        }
        friend ostream& operator<<(ostream& out, const BinaryNode<T> *node) {
            out << node->item;
            return out;
        }

};

int main (int argc, char *argv[]) {
    BinaryNode<int> root(10);
    root.left = new BinaryNode<int>(5);
    root.right = new BinaryNode<int>(15);
    root.subtreeIter();
    // cout << root.subtreeFirst() << " " << root.subtreeLast() << endl;
    cout << root.subtreeFirst() << endl;

    free(root.left);
    free(root.right);
    return 0;
}
