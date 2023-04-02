// cmpt225avl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Basic test program for AVL Tree
// Author: John Edgar
// Date: March 2023

#include <vector>
#include <iostream>
#include "AVLTree.h"
using std::cout;
using std::endl;
using std::vector;

void simpleTest();
template <class T>
bool checkAVLTree(const AVLTree<T>& tree);

int main()
{
    simpleTest();

    cout << endl;
}

void simpleTest()
{
    AVLTree<int> aspen;

   // bool check = aspen.remove(1);
    // cout << check << endl;
    // Method return values
    bool success = aspen.insert(50);
    aspen.remove(50);
    cout << " ===== 3 === "  << endl;
    /*
    bool success2 = aspen.insert(10);
    aspen.insert(12);
    bool success4 = aspen.insert(15);
    bool success3 = aspen.insert(18);
    aspen.insert(22);
    aspen.insert(24);
    aspen.insert(7);
    aspen.insert(14);
    aspen.insert(60);
    aspen.remove(12);
   // aspen.remove(24);
    cout << endl;
    */
    aspen.printPreOrder();
    cout << " ===== 4 === "  << endl;
    cout << endl;

    AVLTree<int> copytest(aspen);
    cout << " ===== 5 === "  << endl;

   // copytest.printPreOrder();

    // aspen.insert(31);
    // aspen.insert(35);
    // aspen.insert(44);
    // aspen.insert(4);
    // aspen.insert(66);
    // aspen.insert(70);
    // aspen.insert(90);
    // aspen.printPreOrder();
    // bool ans = aspen.remove(24);
    // cout << endl << ans << endl;
    //  aspen.printPreOrder();
    // bool result = aspen.search(10);
    // cout << endl;
    // cout << result << endl;
    // vector<int> result2 = aspen.search(60,7);
    //  for (int i = 0; i<result2.size(); i++) {
    //     cout << result2[i] << " ";
    //  }
    // checkAVLTree<int>(aspen);
    // success = aspen.remove(1);
    // vector<int> v = aspen.values();
    // for (int i =0; i<v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    //  int smaller = aspen.closestLess(9);
    //  cout << endl << smaller << endl;
    //  int greater = aspen.closestGreater(12);
    //  cout << greater << endl;
    // int size = aspen.size1();
    // cout << endl << size << endl;
    //int sz = aspen.size();
    
    // AVLTree<int> larch(aspen);
    // aspen = larch;

    cout << endl << "end simple a5 test" << endl;
}

// template <class T>
// bool checkAVLTree(const AVLTree<T>& tree)
// {
//     AVLTreeNode<T>* nd = (AVLTreeNode<T>*)tree.getRoot();
//     cout << "height = " << nd->height << endl;

//     return false;
// }