#include "AVLTree.h"
/*
// no children
        if (node->left == nullptr || node->right == nullptr)
        {
            cout << "======1======" << endl;
            AVLTreeNode<T> *temp = (node->left != nullptr) ? node->left : node->right;
            if(temp == nullptr){
                temp = node;
                //node = nullptr;
                cout << "======2======" << endl;
            }else{
                *node = *temp;
            }
            delete temp;
        }else{
            AVLTreeNode<T> *temp = minNode(node->right);
            node->data = temp->data;
            node->right = removehelper(node->right, temp->data);
        }*/
/*
    // remove helper method
    template <typename T>
    AVLTreeNode<T> * AVLTree<T>::removehelper(AVLTreeNode<T> * node, T value) {
        if (node == nullptr) {
            return node;
        }
        else if (value < node->data) {
            node->left = removehelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = removehelper(node->right, value);
        }

        else {
            // no children
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            // one child on the right
            else if (node->left == nullptr) {
                AVLTreeNode<T>* temp = node;
                node = node->right;
                delete temp;
            }
            // one child on the left
            else if (node->right == nullptr) {
                AVLTreeNode<T>* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                // both children
                AVLTreeNode<T> *temp = minNode(node->right);
                node->data = temp->data;
                node->right = removehelper(node->right, temp->data);
            }
        } 
        node->height = std::max((node->left != nullptr) ? (node->left->height):0, 
                        (node->right != nullptr) ? (node->right->height):0) +1;

        return node;
    }*/