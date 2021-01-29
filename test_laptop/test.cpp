//
// Created by yang zhengtao on 2020/10/23.
//
#include "iostream"
#include "BinaryTree.h"
using namespace std;

int main(){
    BinaryTree<int> Tree;
    Tree.creatTree(10);
    Tree.preOrder();
    cout<<Tree.lChild(10, 10);

    return 0;
}
