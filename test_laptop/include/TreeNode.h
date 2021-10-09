//
// Created by yang zhengtao on 2021/8/30.
//

#ifndef TEST_LAPTOP_TREENODE_H
#define TEST_LAPTOP_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //TEST_LAPTOP_TREENODE_H
