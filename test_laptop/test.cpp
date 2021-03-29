//
// Created by yang zhengtao on 2020/10/23.
//
#include "iostream"
#include "BinaryTree.h"
#include "HfTree.h"
using namespace std;

int main(){
    char ch[] = {"abcdef"};
    int w[] = {10, 12, 5, 2, 4};

    HfTree<char> tree(ch, w, sizeof(w)/ 2);
    HfTree<char>::hfNode result[(sizeof(w) / 2)];

    tree.getCode(result);

    for (int i = 0; i < sizeof(w); ++i) {
        cout<<result[i].data<<" "<<result[i].code<<endl;
    }
    return 0;
}
