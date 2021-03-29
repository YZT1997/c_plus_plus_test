//
// Created by yang zhengtao on 2021/2/6.
//

#ifndef TEST_LAPTOP_HFTREE_H
#define TEST_LAPTOP_HFTREE_H
#include <string>
template<class T>
class HfTree{
private:
    struct Node{                    // 数组中元素
        T data;                     // 节点数据
        int weight;                 // 节点的权重
        int parent, left, right;    // 父结点、左右儿子的指针
    };

    Node *elem;
    int length;

public:
    struct hfNode{                  // 保存哈夫曼编码的类型
        T data;                     // 待编码的字符
        std::string code;           // 对应的哈夫曼编码
    };

    HfTree(const T *x, const int *w, int size);
    void getCode(hfNode result[]);  // 从哈夫曼树生成编码
    ~HfTree(){delete[]elem;}
};

template<class T>
HfTree<T>::HfTree(const T *v, const int *w, int size) {
    const int MAX_INIT = 32767;
    int min1, min2;                 // 最小树，次小树的权值
    int x, y;                       // 最小树、次小树的下标

    // Init
    length = 2 * size;
    elem = new Node[length];

    for (int i = size; i < length; ++i) {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }

    // 归并森林中的树
    for (int i = size - 1; i > 0 ; i--) {
        min1 = min2 = MAX_INIT;
        x = y = 0;
        for (int j = i + 1; j < length; ++j) {
            if (elem[j].parent == 0){
                if (elem[j].weight < min1){             // 元素j最小
                    min2 = min1;
                    min1 = elem[j].weight;
                    x = y;
                    y = j;
                } else if (elem[j].weight < min2)       // 元素j次小
                {
                    min2 = elem[j].weight;
                    x = j;
                }

            }
        }
        elem[i].weight = min1 + min2;
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = i;
        elem[y].parent = i;
    }
}

template<class T>
void HfTree<T>::getCode(hfNode result[]) {
    int size = length / 2;
    int p, s;                   // s是追溯过程中正在处理的结点， p是s的父结点下标

    for (int i = size; i < length; ++i) {
        result[i-size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent; s = i;
        while (p){
            if (elem[p].left == s)
                result[i - size].code = '0' + result[i - size].code;
            else result[i - size].code = '1' + result[i - size].code;
            s = p;
            p = elem[p].parent;
        }
    }
}
#endif //TEST_LAPTOP_HFTREE_H
