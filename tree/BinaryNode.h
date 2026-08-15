#ifndef BINARYNODE_H 
#define BINARYNODE_H 

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryNode
{
private:
    void subTreeIterHelper(bool isOriginal)
    {
        if (this->left)
        {
            this->left->subTreeIterHelper(false);
        }

        cout << this->item << " ";

        if (this->right)
        {
            this->right->subTreeIterHelper(false);
        }

        if (isOriginal)
        {
            cout << "\n";
        }
    }

public:
    T item;
    BinaryNode<T> *parent;
    BinaryNode<T> *left;
    BinaryNode<T> *right;

    BinaryNode(T item)
    {
        this->item = item;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    void subTreeIter() { this->subTreeIterHelper(true); }

    BinaryNode<T> *subTreeFirst()
    {
        if (this->left)
        {
            return this->left->subTreeFirst();
        }
        return this;
    }

    BinaryNode<T> *subTreeLast()
    {
        if (this->right)
        {
            return this->right->subTreeLast();
        }
        return this;
    }

    /*
     * the second case is to return the closest ancestor for which
     * the given node comes to it's left subTree
     */

    BinaryNode<T> *successor()
    {
        if (this->right)
        {
            return this->right->subTreeFirst();
        }

        BinaryNode<T> *current = this;
        while (current->parent != NULL && current->parent->right == current)
        {
            current = current->parent;
        }

        return current->parent;
    }

    /*
     * the second case is to return the closest descendent for which
     * the given node comes to it's left subTree
     */

    BinaryNode<T> *predecessor()
    {
        if (this->left)
        {
            return this->left->subTreeLast();
        }

        BinaryNode<T> *current = this;
        while (current->parent != NULL && current->parent->left == current)
        {
            current = current->parent;
        }
        return current->parent;
    }

    void subTreeInsertBefore(BinaryNode<T> *node)
    {
        if (this->left)
        {
            auto predecessor = this->predecessor();
            predecessor->right = node;
            node->parent = predecessor;
        }
        else
        {
            this->left = node;
            node->parent = this;
        }
    }

    void subTreeInsertAfter(BinaryNode<T> *node)
    {
        if (this->right)
        {
            auto successor = this->successor();
            successor->left = node;
            node->parent = successor;
        }
        else
        {
            this->right = node;
            node->parent = this;
        }
    }

    void subTreeDelete()
    {
        if (this->right)
        {
            auto successor = this->successor();
            swap(this->item, successor->item);
            successor->subTreeDelete();
        }
        else if (this->left)
        {
            auto predecessor = this->predecessor();
            swap(this->item, predecessor->item);
            predecessor->subTreeDelete();
        }
        else
        {
            if (this->parent->left == this)
            {
                this->parent->left = NULL;
                free(this);
            }
            else
            {
                this->parent->right = NULL;
                free(this);
            }
        }
    }

    void freeMemorySubtree()
    {

        if (this->left)
            this->left->freeMemorySubtree();

        if (this->right)
            this->right->freeMemorySubtree();

        if (this->parent)
        {
            if (this->parent->left == this)
            {
                this->parent->left = NULL;
            }
            else
            {
                this->parent->right = NULL;
            }
        }
        delete this;
    }

    friend ostream &operator<<(ostream &out, const BinaryNode<T> &node)
    {
        out << node.item;
        return out;
    }

    friend ostream &operator<<(ostream &out, const BinaryNode<T> *node)
    {
        if (node == NULL)
            out << "null";
        else
            out << node->item;

        return out;
    }
};

#endif
