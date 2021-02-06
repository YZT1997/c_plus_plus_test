//
// Created by yang zhengtao on 2020/10/23.
//
#include "iostream"
#include "BinaryTree.h"

using namespace std;

int main(){
    BinaryTree<int> Tree;
    Tree.creatTree(0);
    Tree.preOrder();
    Tree.midOrder();
    Tree.postOrder();
    Tree.levelOrder();
    printTree(Tree,0);
    return 0;
}
