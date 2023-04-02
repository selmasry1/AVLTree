#pragma once
#include <vector>
#include <iostream>
using namespace std;

// AVL Node Class
template <class T>
class AVLTreeNode
{
public:
    // Should have attributes named:
    // parent - pointer to parent
    AVLTreeNode<T> *parent;
    // left - pointer to left child
    AVLTreeNode<T> *left;
    // right - pointer to right child
    AVLTreeNode<T> *right;
    // data - node's data
    T data;
    // height - node's height
    unsigned int height;

    // Constructors ...
    // default constructor

    AVLTreeNode(T value)
    {
        data = value;
        height = 0;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

// AVL Tree class
template <class T>
class AVLTree
{
private:
    // Tree attributes go here
    // Your tree MUST have a root node named root
    AVLTreeNode<T> *root;
    unsigned int size = 0;
    AVLTreeNode<T> *copy(const AVLTreeNode<T> *node);
    void destructorHelp(AVLTreeNode<T> *node);
    int balancefactor(AVLTreeNode<T> *node);
    int height(AVLTreeNode<T> *node);
    void rotateleft(AVLTreeNode<T> *x);
    void rotateright(AVLTreeNode<T> *x);
    bool helpersearch(AVLTreeNode<T> *node, T value);
    AVLTreeNode<T> *removehelper(AVLTreeNode<T> *node, T value);
    AVLTreeNode<T> *minNode(AVLTreeNode<T> *node);
    void rebalance(AVLTreeNode<T> *node);
    AVLTreeNode<T> *inserthelper(AVLTreeNode<T> *node, T value);
    void valueshelp(AVLTreeNode<T> *node, vector<T> &result);
    void search2help(AVLTreeNode<T> *node, vector<T> &temp);
    // void updateheight(AVLTreeNode<T> * node);

public:
    void printPreOrder();
    // default constructor
    AVLTree();
    // copy constructor
    AVLTree(const AVLTree<T> &other);
    // overloaded assignment operator
    AVLTree<T> &operator=(const AVLTree<T> &other);
    // destructor
    ~AVLTree();
    // insert method
    bool insert(T value);
    // remove method
    bool remove(T value);
    // search method with one parameter
    bool search(T value);
    // search method with two parameters
    vector<T> search(T val1, T val2);
    // closestLess method
    T closestLess(T value);
    // closestGreater method
    T closestGreater(T value);
    // values method
    vector<T> values();
    // size method
    int size1();
    // get root method
    void *getRoot() const { return root; }; // DO NOT REMOVE
};

// AVL Tree Methods go here

// default constructor
template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}
// copy constructor
template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T> &other)
{
    root = nullptr;
    root = copy(other.root);
}

// overloaded assignment operator
template <typename T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &other)
{
    if (this != &other)
    {
        destructorHelp(root);
        root = copy(other.root);
    }
    return *this;
}

// destructor
template <typename T>
AVLTree<T>::~AVLTree()
{
    destructorHelp(root);
    root = nullptr;
}

// insert method
template <typename T>
bool AVLTree<T>::insert(T value)
{
    if (root == nullptr)
    {
        root = new AVLTreeNode<T>(value);
        return true;
    }
    bool result = search(value);
    if (result == 1)
    {
        return false;
    }
    AVLTreeNode<T> *node = inserthelper(root, value);
    size++;
    return true;
}

// remove method
template <typename T>
bool AVLTree<T>::remove(T value)
{
    if (root == nullptr)
    {
        return false;
    }
    bool result = search(value);
    if (result != 1)
    {
        return false;
    }
    AVLTreeNode<T> *node = removehelper(root, value);
    return true;
}
// search method with one parameter
template <typename T>
bool AVLTree<T>::search(T value)
{
    if (root == nullptr)
    {
        return false;
    }
    else
    {
        bool result = helpersearch(root, value);
        return result;
    }
    return false;
}
// search method with two parameters
template <typename T>
vector<T> AVLTree<T>::search(T val1, T val2)
{
    vector<T> result;
    if (val1 > val2)
    {
        swap(val1, val2);
    }
    if (root == nullptr)
    {
        return result;
    }
    vector<T> temp;
    search2help(root, temp);
    int i = 0;
    while (i < temp.size() && temp[i] < val1)
    {
        i++;
    }
    int j = temp.size() - 1;
    while (j >= 0 && temp[j] > val2)
    {
        j--;
    }
    for (int k = i; k <= j; k++)
    {
        result.push_back(temp[k]);
    }
    return result;
}

template <typename T>
void AVLTree<T>::search2help(AVLTreeNode<T> *node, vector<T> &temp)
{
    if (node == nullptr)
    {
        return;
    }
    search2help(node->left, temp);
    temp.push_back(node->data);
    search2help(node->right, temp);
}

// closestLess method
template <typename T>
T AVLTree<T>::closestLess(T value)
{
    if (root == nullptr)
    {
        return value;
    }

    AVLTreeNode<T> *node = root;
    T result = value;

    while (node != nullptr)
    {
        if (node->data < value)
        {
            result = node->data;
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    if (result > value)
    {
        return value;
    }
    else
    {
        return result;
    }
    return value;
}

// closestGreater method
template <typename T>
T AVLTree<T>::closestGreater(T value)
{
    if (root == nullptr)
    {
        return value;
    }

    AVLTreeNode<T> *node = root;
    T result = value;

    while (node != nullptr)
    {
        if (node->data > value)
        {
            result = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    if (result < value)
    {
        return value;
    }
    else
    {
        return result;
    }
    return value;
}

// values method
template <typename T>
vector<T> AVLTree<T>::values()
{
    vector<T> result;
    valueshelp(root, result);

    return result;
}

template <typename T>
void AVLTree<T>::valueshelp(AVLTreeNode<T> *node, vector<T> &result)
{
    if (node == nullptr)
    {
        return;
    }
    valueshelp(node->left, result);
    result.push_back(node->data);
    valueshelp(node->right, result);
}

// size method
template <typename T>
int AVLTree<T>::size1()
{
    return size;
}

// print pre order
template <typename T>
void AVLTree<T>::printPreOrder()
{
    preOrder(root);
}

// balance factor method
template <typename T>
int AVLTree<T>::balancefactor(AVLTreeNode<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return (height(node->left) - height(node->right));
}

// height of node method
template <typename T>
int AVLTree<T>::height(AVLTreeNode<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

// left rotation helper method
template <typename T>
void AVLTree<T>::rotateleft(AVLTreeNode<T> *x)
{
    AVLTreeNode<T> *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else
    {
        if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
    }
    y->left = x;
    x->parent = y;
}

// right rotation helper method
template <typename T>
void AVLTree<T>::rotateright(AVLTreeNode<T> *x)
{
    AVLTreeNode<T> *y = x->left;
    x->left = y->right;
    if (y->right != nullptr)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else
    {
        if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
    }
    y->right = x;
    x->parent = y;
}

template <typename T>
void AVLTree<T>::rebalance(AVLTreeNode<T> *node)
{
    if (balancefactor(node) < 0)
    {
        if (balancefactor(node->right) > 0)
        {
            rotateright(node->right);
            rotateleft(node);
        }
        else
        {
            rotateleft(node);
        }
    }
    else if ((balancefactor(node)) > 0)
    {
        if (balancefactor(node->left) < 0)
        {
            rotateleft(node->left);
            rotateright(node);
        }
        else
        {
            rotateright(node);
        }
    }
}

template <typename T>
void preOrder(AVLTreeNode<T> *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <typename T>
AVLTreeNode<T> *AVLTree<T>::inserthelper(AVLTreeNode<T> *node, T value)
{
    if (node == nullptr)
    {
        return new AVLTreeNode<T>(value);
    }
    if (node->data > value)
    {
        node->left = inserthelper(node->left, value);
    }
    else if (node->data < value)
    {
        node->right = inserthelper(node->right, value);
    }
    else
    {
        rebalance(node);
        return node;
    }
    // check if opposite side node is null
    node->height = std::max((node->left != nullptr) ? (node->left->height) : 0,
                            (node->right != nullptr) ? (node->right->height) : 0) +
                   1;

    return node;
}

template <typename T>
bool AVLTree<T>::helpersearch(AVLTreeNode<T> *node, T value)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (node->data == value)
    {
        return true;
    }
    else if (node->data > value)
    {
        bool result = helpersearch(node->left, value);
        return result;
    }
    else
    {
        bool result = helpersearch(node->right, value);
        return result;
    }
}

// remove helper method
template <typename T>
AVLTreeNode<T> *AVLTree<T>::removehelper(AVLTreeNode<T> *node, T value)
{
    if (node == nullptr)
    {
        return node;
    }
    else if (value < node->data)
    {
        node->left = removehelper(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = removehelper(node->right, value);
    }

    else
    {
        // no children
            if (node->left == nullptr && node->right == nullptr) {
                cout << " ===== 1 === "  << endl;
                delete node;
                cout << " ===== 2 === "  << endl;
                // node = nullptr;
            }
    }
    // node->height = std::max((node->left != nullptr) ? (node->left->height) : 0,
    //                        (node->right != nullptr) ? (node->right->height) : 0) + 1;

    return node;
}

template <typename T>
AVLTreeNode<T> *AVLTree<T>::minNode(AVLTreeNode<T> *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

template <typename T>
void AVLTree<T>::destructorHelp(AVLTreeNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    destructorHelp(node->left);
    destructorHelp(node->right);
    delete node;
}

template <typename T>
AVLTreeNode<T> *AVLTree<T>::copy(const AVLTreeNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    AVLTreeNode<T> *newNode = new AVLTreeNode<T>(node->data);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    newNode->height = node->height;
    return newNode;
}
